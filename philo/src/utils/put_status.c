/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:55:34 by yoda              #+#    #+#             */
/*   Updated: 2024/03/21 18:51:20 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	int		end_flag;

	if (get_current_ms(&time) == false)
		return (error_message("gettimeofday error\n"), end_game_unit(p, NULL));
	time -= p->common->starttime;
	end_flag = get_mutex_int(p->m_end_flag, p->end_flag);
	if (end_flag >= p->common->num_of_philos)
		return (false);
	pthread_mutex_lock(p->m_print);
	printf("%.3lld %d %s\n", time, p->id, get_message(status));
	if (status == TAKE_FORKS)
	{
		printf("%.3lld %d %s\n", time, p->id, get_message(status));
		printf("%.3lld %d %s\n", time, p->id, get_message(EATING));
	}
	pthread_mutex_unlock(p->m_print);
	if (status == DIED)
	{
		set_mutex_int(p->m_end_flag, p->end_flag, p->common->num_of_philos);
		return (true);
	}
	return (true);
}
