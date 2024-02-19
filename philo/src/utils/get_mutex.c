/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:03:17 by yoda              #+#    #+#             */
/*   Updated: 2024/02/20 02:54:59 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_mutex_bool(pthread_mutex_t *m, bool *buf)
{
	bool	ans;

	pthread_mutex_lock(m);
	ans = *buf;
	pthread_mutex_unlock(m);
	return (ans);
}

bool	get_mutex_int(pthread_mutex_t *m, int *buf)
{
	int	ans;

	pthread_mutex_lock(m);
	ans = *buf;
	pthread_mutex_unlock(m);
	return (ans);
}

t_ms	get_mutex_ms(pthread_mutex_t *m, t_ms *buf)
{
	t_ms	ans;

	pthread_mutex_lock(m);
	ans = *buf;
	pthread_mutex_unlock(m);
	return (ans);
}
