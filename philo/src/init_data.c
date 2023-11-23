/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:08:54 by yoda              #+#    #+#             */
/*   Updated: 2023/11/24 01:44:43 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_g_data_sub(t_global_data *p)
{
	int	i;

	p->end_flag = false;
	p->m_end = malloc(sizeof(pthread_mutex_t));
	p->philos = malloc(sizeof(t_philo *) * p->num_of_philo);
	p->fork = malloc(sizeof(pthread_mutex_t *) * p->num_of_philo);
	p->m_meal = malloc(sizeof(pthread_mutex_t *) * p->num_of_philo);
	i = -1;
	while (++i < p->num_of_philo)
	{
		p->philos[i] = malloc(sizeof(t_philo));
		p->fork[i] = malloc(sizeof(pthread_mutex_t));
		p->m_meal[i] = malloc(sizeof(pthread_mutex_t));
	}
	if (!p->philos || !p->fork)
		return (ft_free_four_val(p->m_end, p->philos, p->fork, p->m_meal));
	if (pthread_mutex_init(p->m_end, NULL))
		return (free(p->m_end), false);
	i = -1;
	while (++i < p->num_of_philo)
	{
		if (pthread_mutex_init(p->fork[i], NULL))
			return (mutex_destroy(p->fork, i),
				pthread_mutex_destroy(p->m_end),
				ft_free_four_val(p->m_end, p->philos, p->fork, p->m_meal),
				error_message("mutex_init error\n"));
		if (pthread_mutex_init(p->m_meal[i], NULL))
			return (two_mutex_destroy(p->fork, p->m_meal, i),
				pthread_mutex_destroy(p->fork[i]),
				pthread_mutex_destroy(p->m_end),
				ft_free_four_val(p->m_end, p->philos, p->fork, p->m_meal),
				error_message("mutex_init error\n"));
	}
	return (true);
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

static bool	init_philo(t_global_data p, int count)
{
	p.philos[count]->m_meal = p.m_meal[count];
	p.philos[count]->philo_id = count + 1;
	p.philos[count]->time_to_die = p.time_to_die;
	p.philos[count]->time_to_eat = p.time_to_eat;
	p.philos[count]->time_to_sleep = p.time_to_sleep;
	p.philos[count]->eat_count = 0;
	p.philos[count]->starttime = p.starttime;
	p.philos[count]->left = p.fork[count];
	p.philos[count]->right = p.fork[(count + 1) % p.num_of_philo];
	p.philos[count]->done = false;
	p.philos[count]->end_flag = &(p.end_flag);
	p.philos[count]->m_end = p.m_end;
	return (true);
}

bool	init_philos(t_global_data p)
{
	int	i;

	i = -1;
	while (++i < p.num_of_philo)
		init_philo(p, i);
	return (true);
}