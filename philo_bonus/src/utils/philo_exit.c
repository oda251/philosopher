/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 05:17:11 by yoda              #+#    #+#             */
/*   Updated: 2024/02/20 04:08:46 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all_philos(t_data *data)
{
	int	i;

	if (!data->philos)
		return ;
	i = 0;
	while (i < data->common.num_of_philos)
	{
		if (data->philos[i].pid > 0)
			kill(data->philos[i].pid, SIGKILL);
		i++;
	}
}

void	main_exit(t_data *data, int status)
{
	int	i;

	sem_end(data->s_forks, SEM_FORKS);
	sem_end(data->s_print, SEM_PRINT);
	sem_end(data->s_full, SEM_FULL);
	sem_end(data->s_waiter, SEM_WAITER);
	sem_end(data->s_dead, SEM_DEAD);
	if (data->philos)
	{
		i = 0;
		while (i < data->common.num_of_philos)
		{
			sem_end(data->philos[i].s_eat_count,
					data->philos[i].sem_name);
			i++;
		}
	}
	exit(status);
}
