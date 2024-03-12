/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:55:34 by yoda              #+#    #+#             */
/*   Updated: 2024/03/13 03:48:19 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static char	*get_message(int status)
{
	if (status == TAKE_FORKS)
		return ("has taken a fork");
	if (status == EATING)
		return ("is eating");
	if (status == SLEEPING)
		return ("is sleeping");
	if (status == THINKING)
		return ("is thinking");
	if (status == DIED)
		return ("died");
	return (NULL);
}

bool	put_status(t_philosopher *p, int status)
{
	t_ms	time;

	if (get_current_ms(&time) == false)
		return (error_message("gettimeofday error\n"), false);
	time -= p->common->starttime;
	sem_wait(p->sems->s_print);
	if (status == TAKE_FORKS)
		printf("%.3lld %d %s\n%.3lld %d %s\n",
			time, p->id, get_message(status), time, p->id, get_message(status));
	else 
		printf("%.3lld %d %s\n", time, p->id, get_message(status));
	if (status == DIED)
		return (true);
	sem_post(p->sems->s_print);
	return (true);
}
