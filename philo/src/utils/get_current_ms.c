/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_ms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:23:18 by yoda              #+#    #+#             */
/*   Updated: 2023/11/24 01:25:42 by yoda             ###   ########.fr       */
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
