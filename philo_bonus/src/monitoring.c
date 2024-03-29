/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 07:43:05 by yoda              #+#    #+#             */
/*   Updated: 2024/03/13 04:46:29 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	full_monitoring(t_data *data)
{
	int				i;

	i = 0;
	while (i < data->common.num_of_philos)
	{
		sem_wait(data->sems.s_full);
		i++;
	}
	exit(EXIT_SUCCESS);
}

static void	exit_if_dead(t_philosopher *philo)
{
	t_ms	last_eat;
	t_ms	time;

	last_eat = get_sem_ms(philo->s_last_eat, &(philo->last_eat));
	if (get_current_ms(&time) == false)
	{
		error_message("gettimeofday error\n");
		exit(EXIT_FAILURE);
	}
	if (time - last_eat >= philo->common->time_to_die)
	{
		put_status(philo, DIED);
		exit(EXIT_SUCCESS);
	}
}

void	*unit_monitoring(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (true)
	{
		usleep(100);
		exit_if_dead(philo);
	}
	return (NULL);
}
