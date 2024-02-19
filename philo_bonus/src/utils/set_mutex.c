/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:03:17 by yoda              #+#    #+#             */
/*   Updated: 2024/02/18 09:24:33 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_mutex_int(pthread_mutex_t *m, int *buf, int val)
{
	pthread_mutex_lock(m);
	*buf = val;
	pthread_mutex_unlock(m);
}

void	set_mutex_bool(pthread_mutex_t *m, bool *buf, bool val)
{
	pthread_mutex_lock(m);
	*buf = val;
	pthread_mutex_unlock(m);
}

void	set_mutex_ms(pthread_mutex_t *m, ms *buf, ms val)
{
	pthread_mutex_lock(m);
	*buf = val;
	pthread_mutex_unlock(m);
}
