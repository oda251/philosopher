/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:55:28 by yoda              #+#    #+#             */
/*   Updated: 2023/11/29 17:35:33 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	start_eating(t_philo *p)
{
	pthread_mutex_lock(p->left);
	pthread_mutex_lock(p->right);
	pthread_mutex_lock(p->m_meal);
	p->eat_count++;
	if (get_current_ms(&p->last_eat) == false)
	{
		pthread_mutex_unlock(p->m_meal);
		return (false);
	}
	pthread_mutex_unlock(p->m_meal);
	return (true);
}
