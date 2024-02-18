/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:54:54 by yoda              #+#    #+#             */
/*   Updated: 2024/02/18 08:57:57 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	game(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->common.num_of_philos)
	{
		data->philos[i].last_eat = data->common.starttime;
		if (pthread_create(&(data->tid[i]), NULL, unit_philo, &(data->philos[i])))
			return (end_game(data), error_message("pthread_create error\n"));
		i++;
	}
	if (pthread_create(&(data->monitor_tid), NULL, monitoring, data))
		return (end_game(data), error_message("pthread_create error\n"));
	pthread_join(data->monitor_tid, NULL);
	i = 0;
	while (i < data->common.num_of_philos)
	{
		pthread_join(data->tid[i], NULL);
		i++;
	}
	return (true);
}
