/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:55:28 by yoda              #+#    #+#             */
/*   Updated: 2023/11/22 02:11:11 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	eat(t_philo p, suseconds_t *time_ms)
{
	t_time	time;

	pthread_mutex_lock(p.left);
	pthread_mutex_lock(p.right);
	if (gettimeofday(&time, NULL) == -1)
		return (error_message("gettimeofday error\n"));
	*time_ms = convert_time(time);
	pthread_mutex_lock(p.m_meal);
	p.last_eat = *time_ms;
	pthread_mutex_unlock(p.m_meal);
	return (true);
}