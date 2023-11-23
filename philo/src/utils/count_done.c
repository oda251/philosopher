/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_done.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 04:26:12 by yoda              #+#    #+#             */
/*   Updated: 2023/11/24 01:49:10 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	count_done(t_global_data p)
{
	int	i;
	int	done_count;

	if (p.num_of_must_eat == -1)
		return (false);
	i = 0;
	done_count = 0;
	while (i < p.num_of_philo)
	{
		if (p.philos[i]->done == false)
		{
			pthread_mutex_lock(p.philos[i]->m_meal);
			if (p.philos[i]->eat_count >= p.num_of_must_eat)
			{
				p.philos[i]->done = true;
				done_count++;
			}
			pthread_mutex_unlock(p.philos[i]->m_meal);
		}
		else
			done_count++;
		i++;
	}
	if (done_count == p.num_of_philo)
		return (true);
	return (false);
}