/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_eat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:55:28 by yoda              #+#    #+#             */
/*   Updated: 2024/03/13 03:27:45 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	take_forks(t_philosopher *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(p->left_fork);
		if (put_status(p, TAKE_FORKS) == false)
			return (false);
		pthread_mutex_lock(p->right_fork);
		if (put_status(p, TAKE_FORKS) == false)
		{
			pthread_mutex_unlock(p->left_fork);
			return (false);
		}
	}
	else
	{
		pthread_mutex_lock(p->right_fork);
		if (put_status(p, TAKE_FORKS) == false)
			return (false);
		pthread_mutex_lock(p->left_fork);
		if (put_status(p, TAKE_FORKS) == false)
		{
			pthread_mutex_unlock(p->right_fork);
			return (false);
		}
	}
	return (true);
}

static bool	update_status(t_philosopher *p)
{
	t_ms	time;

	if (get_current_ms(&time) == false)
		return (end_game_unit(p, "gettimeofday error\n"));
	set_mutex_ms(p->m_last_eat, &(p->last_eat), time);
	(p->eat_count)++;
	if (p->eat_count == p->common->times_to_eat)
	{
		pthread_mutex_lock(p->m_end_flag);
		(*(p->end_flag))++;
		pthread_mutex_unlock(p->m_end_flag);
	}
	return (true);
}

bool	act_eat(t_philosopher *p)
{
	bool	result;

	take_forks(p);
	put_status(p, EATING);
	result = usleep_ms(p->common->time_to_eat);
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
	if (result == false)
		return (end_game_unit(p, NULL));
	result = update_status(p);
	return (result);
}
