/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 05:17:11 by yoda              #+#    #+#             */
/*   Updated: 2024/02/19 16:27:11 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philos(t_philosopher *philos, int size)
{
	int	i;

	i = 0;
	while (i < size && philos[i].id != 0)
	{
		pthread_mutex_destroy(philos[i].m_last_eat);
		free(philos[i].m_last_eat);
		i++;
	}
	free(philos);
}

void	free_monitor(t_monitor monitor)
{
	pthread_mutex_destroy(&(monitor.m_end_flag));
}

void	free_data(t_data *data, int setup_progress)
{
	int	i;

	if (setup_progress < 0)
	{
		free_monitor(data->monitor);
		setup_progress = data->common.num_of_philos;
	}
	if (data->forks)
	{
		i = 0;
		while (i < setup_progress)
		{
			pthread_mutex_destroy(&(data->forks[i]));
			i++;
		}
		free(data->forks);
	}
	if (data->philos)
		free_philos(data->philos, data->common.num_of_philos);
}