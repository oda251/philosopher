/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:55:28 by yoda              #+#    #+#             */
/*   Updated: 2023/11/24 01:30:24 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	eat(t_philo p, ms *time_ms)
{
	pthread_mutex_lock(p.left);
	pthread_mutex_lock(p.right);
	if (get_current_ms(time_ms) == false)
		return (false);
	pthread_mutex_lock(p.m_meal);
	p.last_eat = *time_ms;
	pthread_mutex_unlock(p.m_meal);
	return (true);
}