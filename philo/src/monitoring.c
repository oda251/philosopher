/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 07:43:05 by yoda              #+#    #+#             */
/*   Updated: 2024/02/18 09:52:19 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_dead(t_data *data, int i, ms time)
{
	ms	last_eat;

	get_mutex_ms(&(data->philos[i].m_last_eat), &last_eat);
	if (time - last_eat >= data->common.time_to_die)
	{
		end_game(data);
		put_status(time, i + 1, DIED);
		return (true);
	}
	return (false);
}

void	*monitoring(void *arg)
{
	int			i;
	t_data		*data;
	ms			time;

	data = (t_data *)arg;
	while (true)
	{
		usleep(1000);
		if (get_current_ms(&time) == false)
			return (NULL);
		i = -1;
		while (++i < data->common.num_of_philos)
		{
			if (is_dead(data, i, time) == true)
				return (NULL);
		}
	}
	return (NULL);
}
