/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 07:43:05 by yoda              #+#    #+#             */
/*   Updated: 2024/02/19 16:25:56 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_dead(t_data *data, int i)
{
	ms	last_eat;
	ms	time;

	last_eat = get_mutex_ms(data->philos[i].m_last_eat, &(data->philos[i].last_eat));
	if (get_current_ms(&time) == false)
		return (end_game(data), error_message("gettimeofday error\n"), true);
	if (time - last_eat >= data->common.time_to_die)
	{
		end_game(data);
		put_status(time - data->common.starttime, i + 1, DIED);
		return (true);
	}
	return (false);
}

void	*monitoring(void *arg)
{
	int			i;
	t_data		*data;

	data = (t_data *)arg;
	while (true)
	{
		usleep(1000);
		i = -1;
		while (++i < data->common.num_of_philos)
		{
			if (is_dead(data, i) == true)
				return (NULL);
		}
		if (get_mutex_int(&(data->monitor.m_end_flag),
			&(data->monitor.end_flag)) >= data->common.num_of_philos)
			return (NULL);
	}
	return (NULL);
}
