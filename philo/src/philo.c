/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:54:54 by yoda              #+#    #+#             */
/*   Updated: 2023/11/19 22:25:14 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_fork(t_global_data p)
{
	int			left;
	int			right;

	left = p.philo_id;
	right = (p.philo_id + 1) % p.num_of_philo;
	return (0);
}

void	*unit_philo(void *arg)
{
	t_global_data	p;

	p = *(t_global_data *)arg;
	if (gettimeofday(&(p.starttime), NULL) == -1)
		return (NULL);
	check_fork(p);
	return (NULL);
}

void	philo(t_global_data p)
{
	int			i;

	i = -1;
	while (++i < p.num_of_philo)
		pthread_mutex_init(&(p.mutex[i]), NULL);
	i = -1;
	while (++i < p.num_of_philo)
	{
		p.philo_id = i;
		pthread_create(&(p.tid[i]), NULL, unit_philo, &p);
		pthread_detach(p.tid[i]);
	}
	i = -1;
	while (++i < p.num_of_philo)
		pthread_join(p.tid[i], NULL);
}
