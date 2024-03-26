/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:00:10 by yoda              #+#    #+#             */
/*   Updated: 2024/03/21 23:14:09 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	wait_start(t_common_data *common)
{
	t_ms	time;

	if (get_current_ms(&time) == false)
		return (error_message("gettimeofday error\n"));
	while (time < common->starttime)
	{
		usleep(100);
		if (get_current_ms(&time) == false)
			return (error_message("gettimeofday error\n"));
	}
	return (true);
}
