/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:55:34 by yoda              #+#    #+#             */
/*   Updated: 2023/11/24 01:45:52 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	put_status(ms time, int philo_id, char *status)
{
	ms			tmp_ms;

	if (get_current_ms(&tmp_ms) == false)
		return (false);
	printf("%.3lld %d %s\n", time - tmp_ms, philo_id, status);
	return (true);
}
