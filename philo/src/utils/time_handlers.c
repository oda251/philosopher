/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:23:18 by yoda              #+#    #+#             */
/*   Updated: 2024/02/18 09:14:03 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_current_ms(ms *current_ms)
{
	t_time		tmp;

	if (gettimeofday(&tmp, NULL) == -1)
		return (false);
	*current_ms = convert_time(tmp);
	return (true);
}

bool	get_passed_time(t_common_data *common, ms *dest)
{
	if (get_current_ms(dest) == false)
		return (false);
	*dest -= common->starttime;
	return (true);
}

ms	convert_time(t_time time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	usleep_ms(ms time)
{
	usleep(time * 1000);
}
