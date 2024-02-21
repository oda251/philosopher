/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_think.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 09:24:35 by yoda              #+#    #+#             */
/*   Updated: 2024/02/21 14:31:14 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	act_think(t_philosopher *p)
{
	t_ms	time;

	if (get_passed_time(p->common, &time) == false)
	{
		error_message("gettimeofday error");
		exit(EXIT_FAILURE);
	}
	put_status(p->sems->s_print, time, p->id, THINKING);
}
