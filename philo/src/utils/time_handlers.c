/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:23:18 by yoda              #+#    #+#             */
/*   Updated: 2024/03/13 02:02:13 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_current_ms(t_ms *current_ms)
{
	t_time		tmp;

	if (gettimeofday(&tmp, NULL) == -1)
		return (false);
	*current_ms = convert_time(tmp);
	return (true);
}

bool	get_passed_time(t_common_data *common, t_ms *dest)
{
	if (get_current_ms(dest) == false)
		return (false);
	*dest -= common->starttime;
	return (true);
}

t_ms	convert_time(t_time time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

bool	usleep_ms(t_ms time)
{
	long long	start;
	long long	current;

	if (get_current_ms(&start) == false)
		return (error_message("gettimeofday error\n"));
	current = start;
	while (current - start < time)
	{
		usleep(100);
		if (get_current_ms(&current) == false)
			return (error_message("gettimeofday error\n"));
	}
	return (true);
}
