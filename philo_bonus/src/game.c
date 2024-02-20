/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:54:54 by yoda              #+#    #+#             */
/*   Updated: 2024/02/21 02:55:43 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	game(t_data *data)
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
	if (pthread_create(&(data->death_monitor), NULL, death_monitor, data) != 0)
		return (kill_all_philos(data), error_message("pthread_create error\n"));
	if (pthread_create(&(data->full_monitor), NULL, full_monitor, data) != 0)
		return (kill_all_philos(data), error_message("pthread_create error\n"));
	return (true);
}
