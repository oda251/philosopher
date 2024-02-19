/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:54:54 by yoda              #+#    #+#             */
/*   Updated: 2024/02/20 02:35:59 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	game(t_data *data)
{
	int	i;

	if (get_current_ms(&(data->common.starttime)) == false)
		return (end_game(data), error_message("gettimeofday error\n"));
	i = 0;
	while (i < data->common.num_of_philos)
	{
		((data->philos)[i]).last_eat = data->common.starttime;
		if (pthread_create(&(data->tid[i]), NULL,
			unit_philo, &((data->philos)[i])) != 0)
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
