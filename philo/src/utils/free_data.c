/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 05:17:11 by yoda              #+#    #+#             */
/*   Updated: 2024/03/21 18:07:51 by yoda             ###   ########.fr       */
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

void	free_data(t_data *data, int setup_progress)
{
	int	i;

	pthread_mutex_destroy(&(data->m_print));
	if (data->tid)
		free(data->tid);
	if (data->waiters)
		free(data->waiters);
	if (data->waiter_tid)
		free(data->waiter_tid);
	if (data->forks)
	{
		i = 0;
		while (i < setup_progress)
		{
			pthread_mutex_destroy(&(data->forks[i]));
			pthread_mutex_destroy(&(data->waiters[i]));
			i++;
		}
		free(data->forks);
	}
	if (setup_progress == -2)
		return ;
	pthread_mutex_destroy(&(data->m_print));
	if (setup_progress < 0)
	{
		pthread_mutex_destroy(&(data->m_end_flag));
		setup_progress = data->common.num_of_philos;
	}
	if (data->philos)
		free_philos(data->philos, data->common.num_of_philos);
}
