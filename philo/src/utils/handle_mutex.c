/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:03:17 by yoda              #+#    #+#             */
/*   Updated: 2023/11/22 02:22:11 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_mutex_bool(pthread_mutex_t *m, bool *b)
{
	bool	ans;

	pthread_mutex_lock(m);
	ans = *b;
	pthread_mutex_unlock(m);
	return (ans);
}

bool	is_dead(t_global_data p, int i, suseconds_t time_ms)
{
	bool	ans;

	pthread_mutex_lock(p.philos[i]->m_meal);
	ans = time_ms - p.philos[i]->last_eat > p.time_to_die * 1000;
	pthread_mutex_unlock(p.philos[i]->m_meal);
	return (ans);
}

bool	turn_true(pthread_mutex_t *m, bool *b)
{
	pthread_mutex_lock(m);
	*b = true;
	pthread_mutex_unlock(m);
	return (true);
}