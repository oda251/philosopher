/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:55:34 by yoda              #+#    #+#             */
/*   Updated: 2023/11/21 04:19:28 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	put_status(suseconds_t time, int philo_id, char *status)
{
	t_time	tmp;

	if (time < 0 && gettimeofday(&tmp, NULL) == -1)
		return (false);
	time = convert_time(tmp);
	printf("%ld %d %s\n", time, philo_id, status);
	return (true);
}
