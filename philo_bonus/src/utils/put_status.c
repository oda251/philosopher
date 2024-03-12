/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:55:34 by yoda              #+#    #+#             */
/*   Updated: 2024/03/13 02:29:24 by yoda             ###   ########.fr       */
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

bool	put_status(sem_t *s_print, t_ms passed_time, int philo_id, int status)
{
	sem_wait(s_print);
	printf("%.3lld %d %s\n", passed_time, philo_id, get_message(status));
	if (status == DIED)
		return (true);
	sem_post(s_print);
	return (true);
}
