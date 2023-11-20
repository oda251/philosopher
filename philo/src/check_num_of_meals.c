/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_of_meals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 04:26:12 by yoda              #+#    #+#             */
/*   Updated: 2023/11/21 04:30:16 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_num_of_meals(t_global_data p)
{
	int	i;
	int	done_count;

	i = 0;
	while (i < p.num_of_philo)
	{
		if (p.philos[i].done == false)
		{
			pthread_mutex_lock(&(p.philos[i].meal));
			if (p.philos[i].eat_count >= p.num_of_must_eat)
			{
				p.philos[i].done = true;
				done_count++;
			}
			pthread_mutex_unlock(&(p.philos[i].meal));
		}
		else
			done_count++;
		i++;
	}
	if (done_count == p.num_of_philo)
		return (true);
	return (false);
}