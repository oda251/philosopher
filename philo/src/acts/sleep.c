/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:08:22 by yoda              #+#    #+#             */
/*   Updated: 2024/02/18 09:23:32 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	sleep(t_philosopher *p)
{
	ms	time;

	
	if (get_passed_time(p->common, &time) == false)
		return (end_game_unit(p), error_message("gettimeofday error\n"));
	if (get_mutex_int(p->m_end_flag, p->end_flag) >= p->common->num_of_philos)
		return (false);
	put_status(time, p->id, SLEEPING);
	usleep(p->common->time_to_sleep * 1000);
	return (true);
}