/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:08:54 by yoda              #+#    #+#             */
/*   Updated: 2024/03/21 23:09:58 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	calloc_things(t_data *data)
{
	data->forks = ft_calloc(
			data->common.num_of_philos, sizeof(pthread_mutex_t));
	data->waiters = ft_calloc(
			data->common.num_of_philos, sizeof(pthread_mutex_t));
	data->tid = ft_calloc(
			data->common.num_of_philos, sizeof(pthread_t));
	data->waiter_tid = ft_calloc(
			data->common.num_of_philos, sizeof(pthread_t));
	if (!data->forks || !data->tid || !data->waiters || !data->waiter_tid)
		return (free_data(data, -2), error_message("malloc error\n"));
	return (true);
}

bool	setup_data(t_data *data)
{
	int	i;

	if (mutex_init(&(data->m_print)) == false)
		return (error_message("mutex_init error\n"));
	if (calloc_things(data) == false)
		return (false);
	if (mutex_init(&(data->m_print)) == false)
		return (free_data(data, 0), error_message("mutex_init error\n"));
	i = -1;
	while (++i < data->common.num_of_philos)
	{
		if (mutex_init(&(data->forks[i])) == false)
			return (free_data(data, i), error_message("mutex_init error\n"));
		if (mutex_init(&(data->waiters[i])) == false)
			return (pthread_mutex_destroy(&(data->forks[i])),
				free_data(data, i), error_message("mutex_init error\n"));
	}
	if (mutex_init(&(data->m_end_flag)) == false)
		return (free_data(data, i), error_message("mutex_init error\n"));
	return (true);
}
