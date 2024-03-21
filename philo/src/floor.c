/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:01:33 by yoda              #+#    #+#             */
/*   Updated: 2024/03/21 18:57:06 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*serve_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->common.num_of_philos)
	{
		pthread_mutex_unlock(&(data->waiters[i]));
		i++;
	}
	return (NULL);
}

void	*floor_(void *arg)
{
	int		i;
	int		tmp;
	int		start;
	t_data	*data;

	data = (t_data *)arg;
	if (wait_start(&(data->common)) == false)
		return (end_game(data), NULL);
	start = -1;
	while (true)
	{
		start = (start + 1) % data->common.num_of_philos;
		i = -1;
		while (++i < data->common.num_of_philos / 2)
		{
			tmp = (i * 2 + start) % data->common.num_of_philos;
			pthread_mutex_unlock(&(data->waiters[tmp]));
		}
		usleep_ms(60);
		while (--i >= 0)
		{
			tmp = (i * 2 + start) % data->common.num_of_philos;
			pthread_mutex_lock(&(data->waiters[tmp]));
		}
		if (get_mutex_int(&(data->m_end_flag), &(data->end_flag)) >= data->common.num_of_philos)
			return (serve_all(data));
	}
	return (serve_all(data));
}
