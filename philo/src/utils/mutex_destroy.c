/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:55:24 by yoda              #+#    #+#             */
/*   Updated: 2023/11/24 01:07:44 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	mutex_destroy(pthread_mutex_t **mutex, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(mutex[i]);
		i++;
	}
	return (false);
}

bool	two_mutex_destroy(pthread_mutex_t **mutex1, pthread_mutex_t **mutex2, int num)
{
	mutex_destroy(mutex1, num);
	mutex_destroy(mutex2, num);
	return (false);
}
