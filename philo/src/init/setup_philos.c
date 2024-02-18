/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:08:54 by yoda              #+#    #+#             */
/*   Updated: 2024/02/18 10:14:41 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	setup_philo(t_data *data, int i)
{
	if (mutex_init(&(data->philos[i].m_last_eat)))
		return (
			free_data(data, -1),
			error_message("mutex_init error\n")
		);
	data->philos[i].id = i + 1;
	data->philos[i].common = &(data->common);
	data->philos[i].left_fork = &(data->forks[i]);
	data->philos[i].right_fork = &(data->forks[(i + 1) % data->common.num_of_philos]);
	data->philos[i].end_flag = &(data->monitor.end_flag);
	data->philos[i].m_end_flag = &(data->monitor.m_end_flag);
	return (true);
}

bool	setup_philos(t_data *data)
{
	int	i;

	data->philos = ft_calloc(data->common.num_of_philos, sizeof(t_philosopher));
	if (!data->philos)
		return (free_data(data, -1), error_message("malloc error\n"));
	i = 0;
	while (i < data->common.num_of_philos)
	{
		if (setup_philo(data, i) == false)
			return (false);
		i++;
	}
	return (true);
}