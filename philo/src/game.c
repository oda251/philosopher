/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:54:54 by yoda              #+#    #+#             */
/*   Updated: 2024/03/26 17:13:44 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	setup(t_data *data)
{
	if (get_current_ms(&(data->common.starttime)) == false)
		return (error_message("gettimeofday error\n"));
	data->common.starttime += 1000;
	for (int i=0; i<data->common.num_of_philos; i++)
		data->philos[i].last_eat = data->common.starttime;
	return (true);
}

bool	game(t_data *data)
{
	int	i;

	if (setup(data) == false)
		return (false);
	if (pthread_create(&(data->floor_tid), NULL, floor_, data))
		return (error_message("pthread_create error\n"));
	i = 0;
	while (i < data->common.num_of_philos)
	{
		if (pthread_create(&(data->tid[i]), NULL,
				unit_philo, &((data->philos)[i])) != 0)
			return (end_game(data), error_message("pthread_create error\n"));
		i++;
	}
	if (pthread_create(&(data->monitor_tid), NULL, monitoring, data))
		return (end_game(data), error_message("pthread_create error\n"));
	pthread_join(data->floor_tid, NULL);
	pthread_join(data->monitor_tid, NULL);
	i = 0;
	while (i < data->common.num_of_philos)
	{
		pthread_join(data->tid[i], NULL);
		i++;
	}
	return (true);
}
