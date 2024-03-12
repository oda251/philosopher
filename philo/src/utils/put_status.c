/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:55:34 by yoda              #+#    #+#             */
/*   Updated: 2024/03/13 02:27:42 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*get_status_message(int status)
{
	if (status == TAKE_FORKS)
		return ("has taken a fork");
	if (status == EATING)
		return ("is eating");
	if (status == SLEEPING)
		return ("is sleeping");
	if (status == THINKING)
		return ("is thinking");
	if (status == DIED)
		return ("died");
	return (NULL);
}

bool	put_status(pthread_mutex_t *m_print,
	t_ms passed_time, int philo_id, int status)
{
	pthread_mutex_lock(m_print);
	printf("%.3lld %d %s\n", passed_time, philo_id, get_status_message(status));
	pthread_mutex_unlock(m_print);
	return (true);
}

bool	put_status_if_not_end(t_philosopher *p, t_ms passed_time, int status)
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
