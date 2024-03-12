/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:08:22 by yoda              #+#    #+#             */
/*   Updated: 2024/03/13 01:56:02 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	act_sleep(t_philosopher *p)
{
	t_ms	time;

	if (get_passed_time(p->common, &time) == false)
		return (end_game_unit(p, "gettimeofday error\n"));
	if (put_status_if_not_end(p, time, SLEEPING) == false)
		return (false);
	if (usleep_ms(p->common->time_to_sleep) == false)
		return (end_game_unit(p, NULL));
	return (true);
}
