/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_eat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:55:28 by yoda              #+#    #+#             */
/*   Updated: 2024/03/13 02:02:22 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	update_status(t_philosopher *p)
{
	t_ms	time;

	if (get_current_ms(&time) == false)
		return (end_game_unit(p, "gettimeofday error\n"));
	set_mutex_ms(p->m_last_eat, &(p->last_eat), time);
	time -= p->common->starttime;
	(p->eat_count)++;
	pthread_mutex_lock(p->m_end_flag);
	if (*(p->end_flag) >= p->common->num_of_philos)
	{
		pthread_mutex_unlock(p->m_end_flag);
		return (false);
	}
	put_status(p->m_print, time, p->id, TAKE_FORKS);
	put_status(p->m_print, time, p->id, EATING);
	if (p->eat_count == p->common->times_to_eat)
		(*(p->end_flag))++;
	pthread_mutex_unlock(p->m_end_flag);
	return (true);
}

bool	act_eat(t_philosopher *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(p->left_fork);
		pthread_mutex_lock(p->right_fork);
	}
	else
	{
		pthread_mutex_lock(p->right_fork);
		pthread_mutex_lock(p->left_fork);
	}
	if (update_status(p) == false)
	{
		pthread_mutex_unlock(p->left_fork);
		pthread_mutex_unlock(p->right_fork);
		return (false);
	}
	if (usleep_ms(p->common->time_to_eat) == false)
		return (end_game_unit(p, NULL));
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
	return (true);
}
