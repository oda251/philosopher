/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 07:43:05 by yoda              #+#    #+#             */
/*   Updated: 2024/03/21 18:57:55 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_dead(t_data *data, t_philosopher *philo)
{
	t_ms	last_eat;
	t_ms	time;

	last_eat = get_mutex_ms(philo->m_last_eat, &(philo->last_eat));
	if (get_current_ms(&time) == false)
		return (end_game(data), error_message("gettimeofday error\n"), true);
	if (time - last_eat >= data->common.time_to_die)
		return (true);
	return (false);
}

void	*monitoring(void *arg)
{
	int			i;
	t_data		*data;
	int			end_flag;

	data = (t_data *)arg;
	if (wait_start(&(data->common)) == false)
		return (end_game(data), NULL);
	while (true)
	{
		i = -1;
		while (++i < data->common.num_of_philos)
		{
			if (is_dead(data, &(data->philos[i])) == true)
				return (put_status(&(data->philos[i]), DIED), NULL);
		}
		end_flag = get_mutex_int(&(data->m_end_flag), &end_flag);
		if (end_flag >= data->common.num_of_philos)
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
