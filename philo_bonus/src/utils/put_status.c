/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:55:34 by yoda              #+#    #+#             */
/*   Updated: 2024/02/21 13:01:47 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	put_status(sem_t *s_print,
	t_ms passed_time, int philo_id, char *status)
{
	sem_wait(s_print);
	printf("%.3lld %d %s\n", passed_time, philo_id, status);
	sem_post(s_print);
	return (true);
}
