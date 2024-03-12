/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:08:22 by yoda              #+#    #+#             */
/*   Updated: 2024/03/13 02:15:15 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	act_sleep(t_philosopher *p)
{
	t_ms	time;

	if (get_passed_time(p->common, &time) == false)
	{
		error_message("gettimeofday error");
		exit(EXIT_FAILURE);
	}
	put_status(p->sems->s_print, time, p->id, SLEEPING);
	if (usleep_ms(p->common->time_to_sleep) == false)
		exit(EXIT_FAILURE);
}
