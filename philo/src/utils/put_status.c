/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:55:34 by yoda              #+#    #+#             */
/*   Updated: 2024/02/20 02:55:07 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	put_status(pthread_mutex_t *m_print,
	t_ms passed_time, int philo_id, char *status)
{
	pthread_mutex_lock(m_print);
	printf("%.3lld %d %s\n", passed_time, philo_id, status);
	pthread_mutex_unlock(m_print);
	return (true);
}

bool	put_status_if_not_end(t_philosopher *p, t_ms passed_time, char *status)
{
	pthread_mutex_lock(p->m_end_flag);
	if (*(p->end_flag) >= p->common->num_of_philos)
	{
		pthread_mutex_unlock(p->m_end_flag);
		return (false);
	}
	put_status(p->m_print, passed_time, p->id, status);
	pthread_mutex_unlock(p->m_end_flag);
	return (true);
}
