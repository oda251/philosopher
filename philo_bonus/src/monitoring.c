/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 07:43:05 by yoda              #+#    #+#             */
/*   Updated: 2024/02/23 21:51:23 by yoda             ###   ########.fr       */
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

	sem_wait(philo->s_last_eat);
	last_eat = philo->last_eat;
	sem_post(philo->s_last_eat);
	if (get_current_ms(&time) == false)
	{
		error_message("gettimeofday error\n");
		exit(EXIT_FAILURE);
	}
	if (time - last_eat >= philo->common->time_to_die)
	{
		time -= philo->common->starttime;
		sem_wait(philo->sems->s_dead);
		put_status(philo->sems->s_print, time, philo->id, DIED);
		exit(EXIT_SUCCESS);
	}
}

void	*unit_monitoring(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (true)
	{
		usleep(1000);
		exit_if_dead(philo);
	}
	return (NULL);
}
