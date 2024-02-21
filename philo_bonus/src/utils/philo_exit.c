/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 05:17:11 by yoda              #+#    #+#             */
/*   Updated: 2024/02/21 14:35:54 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all_philos(t_data *data)
{
	int	i;

	if (data->full_monitor > 0)
		kill(data->full_monitor, SIGKILL);
	if (!data->philos)
		return ;
	i = 0;
	while (i < data->common.num_of_philos)
	{
		if (data->philos_pid[i] > 0)
			kill(data->philos_pid[i], SIGKILL);
		else
			break ;
		i++;
	}
}

void	main_exit(t_data *data, int status)
{
	int	i;

	sem_kill(data->sems.s_forks, SEM_FORKS);
	sem_kill(data->sems.s_print, SEM_PRINT);
	sem_kill(data->sems.s_full, SEM_FULL);
	sem_kill(data->sems.s_waiter, SEM_WAITER);
	if (data->philos)
	{
		i = 0;
		while (i < data->common.num_of_philos)
		{
			if (data->philos[i].sem_name)
				sem_kill(data->philos[i].s_last_eat,
						data->philos[i].sem_name);
			i++;
		}
	}
	exit(status);
}
