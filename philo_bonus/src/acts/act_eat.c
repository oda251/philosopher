/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_eat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:55:28 by yoda              #+#    #+#             */
/*   Updated: 2024/03/13 03:50:33 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	update_status(t_philosopher *p)
{
	t_ms			time;

	if (get_current_ms(&time) == false)
	{
		error_message("gettimeofday error");
		exit(EXIT_FAILURE);
	}
	set_sem_ms(p->s_last_eat, &(p->last_eat), time);
}

void	act_eat(t_philosopher *p)
{
	t_shared_sems	*sems;

	sems = p->sems;
	sem_wait(sems->s_waiter);
	sem_wait(sems->s_forks);
	sem_wait(sems->s_forks);
	put_status(p, TAKE_FORKS);
	put_status(p, EATING);
	(p->eat_count)++;
	if (p->eat_count == p->common->times_to_eat)
		sem_post(sems->s_full);
	if (usleep_ms(p->common->time_to_eat) == false)
		exit(EXIT_FAILURE);
	update_status(p);
	sem_post(sems->s_forks);
	sem_post(sems->s_forks);
	sem_post(sems->s_waiter);
}
