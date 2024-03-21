/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_eat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:55:28 by yoda              #+#    #+#             */
/*   Updated: 2024/03/21 22:35:44 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

	pthread_mutex_lock(p->m_waiter);
	pthread_mutex_lock(p->left_fork);
	pthread_mutex_lock(p->right_fork);
	result = put_status(p, TAKE_FORKS);
	result = result && usleep_ms(p->common->time_to_eat);
	pthread_mutex_unlock(p->right_fork);
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->m_waiter);
	if (result == false)
		return (end_game_unit(p, NULL));
	result = update_status(p);
	return (result);
}
