/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:08:54 by yoda              #+#    #+#             */
/*   Updated: 2023/11/22 02:15:13 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_g_data_sub(t_global_data *p)
{
	p->end_flag = false;
	if (pthread_mutex_init(p->m_end, NULL))
		return (false);
	p->philos = malloc(sizeof(t_philo *) * p->num_of_philo);
	p->fork = malloc(sizeof(pthread_mutex_t *) * p->num_of_philo);
	if (!p->philos || !p->fork)
		return (pthread_mutex_destroy(p->m_end),
			ft_free_two_val(p->philos, p->fork));
}

bool	init_global_data(int argc, char **argv, t_global_data *p)
{
	if (!(argc == 5 || argc == 6))
		return (false);
	p->num_of_philo = ft_atoi(argv[1]);
	p->time_to_die = ft_atoi(argv[2]);
	p->time_to_eat = ft_atoi(argv[3]);
	p->time_to_sleep = ft_atoi(argv[4]);
	if (p->num_of_philo <= 0 || p->time_to_die <= 0
		|| p->time_to_eat <= 0 || p->time_to_sleep <= 0)
		return (false);
	p->num_of_must_eat = -1;
	if (argc == 6)
	{
		p->num_of_must_eat = ft_atoi(argv[5]);
		if (p->num_of_must_eat <= 0)
			return (false);
	}
	if (init_g_data_sub(p) == false)
		return (false);
	return (true);
}

bool	init_philo(t_global_data p, int count)
{
	int	i;

	if (pthread_mutex_init(p.philos[count]->m_meal, NULL))
	{
		i = 0;
		while (i < count)
			pthread_mutex_destroy(p.philos[i++]->m_meal);
		return (false);
	}
	p.philos[count]->philo_id = count + 1;
	p.philos[count]->time_to_die = p.time_to_die;
	p.philos[count]->time_to_eat = p.time_to_eat;
	p.philos[count]->time_to_sleep = p.time_to_sleep;
	p.philos[count]->eat_count = 0;
	p.philos[count]->starttime = p.starttime;
	p.philos[count]->last_eat = convert_time(p.starttime);
	p.philos[count]->left = p.fork[count];
	p.philos[count]->right = p.fork[(count + 1) % p.num_of_philo];
	p.philos[count]->done = false;
	p.philos[count]->end_flag = &(p.end_flag);
	p.philos[count]->m_end = p.m_end;
	return (true);
}
