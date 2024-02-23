/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:54:54 by yoda              #+#    #+#             */
/*   Updated: 2024/02/23 21:53:01 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	wait_all_processes(t_data *data);

int	simulation(t_data *data)
{
	int	i;

	if (get_current_ms(&(data->common.starttime)) == false)
		return (error_message("gettimeofday error\n"));
	i = 0;
	while (i < data->common.num_of_philos)
	{
		((data->philos)[i]).last_eat = data->common.starttime;
		data->philos_pid[i] = fork();
		if (data->philos_pid[i] == -1)
			return (kill_all_philos(data), error_message("fork error\n"));
		else if (data->philos_pid[i] == 0)
			unit_philo(&((data->philos)[i]));
		i++;
	}
	init_child_process(&(data->full_monitor), full_monitoring, data);
	return (wait_all_processes(data));
}

int	wait_all_processes(t_data *data)
{
	int	i;
	int	tmp;
	int	status;

	i = 0;
	status = 0;
	while (i < data->common.num_of_philos + 1)
	{
		waitpid(-1, &tmp, 0);
		if (WIFEXITED(status))
		{
			kill_all_philos(data);
			status = WEXITSTATUS(status);
		}
		if (errno == ECHILD)
			break ;
		i++;
	}
	return (status);
}
