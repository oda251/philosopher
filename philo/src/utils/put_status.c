/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:55:34 by yoda              #+#    #+#             */
/*   Updated: 2023/11/19 22:16:44 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	put_status(suseconds_t start, int philo_id, char *status)
{
	t_time	now;

	if (gettimeofday(&now, NULL) == -1)
		return (false);
	printf("%ld %d %s\n", now.tv_usec - start, philo_id, status);
	return (true);
}
