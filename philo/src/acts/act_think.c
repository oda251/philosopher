/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_think.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:24:35 by yoda              #+#    #+#             */
/*   Updated: 2024/02/23 19:14:22 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	act_think(t_philosopher *p)
{
	t_ms	time;

	if (get_passed_time(p->common, &time) == false)
		return (end_game_unit(p, "gettimeofday error\n"));
	if (put_status_if_not_end(p, time, THINKING) == false)
		return (false);
	return (true);
}
