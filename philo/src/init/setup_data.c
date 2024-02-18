/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:08:54 by yoda              #+#    #+#             */
/*   Updated: 2024/02/18 10:14:04 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	setup_data(t_data *data)
{
	int	i;

	ft_bzero(data, sizeof(t_data));
	ft_bzero(&(data->monitor), sizeof(t_monitor));
	data->forks = ft_calloc(
		data->common.num_of_philos, sizeof(pthread_mutex_t));
	data->tid = ft_calloc(
		data->common.num_of_philos, sizeof(pthread_t));
	if (!data->forks || !data->tid)
		return (free_data(data, -1), error_message("calloc error\n"));
	i = -1;
	while (++i < data->common.num_of_philos)
	{
		if (mutex_init(&(data->forks[i])))
			return (free_data(data, i), error_message("mutex_init error\n"));
	}
	if (mutex_init(&(data->monitor.m_end_flag)))
		return (free_data(data, i), error_message("mutex_init error\n"));
	return (true);
}
