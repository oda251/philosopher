/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:52:26 by yoda              #+#    #+#             */
/*   Updated: 2023/11/19 19:20:40 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_global_data(int argc, char **argv, t_global_data *p);

int	main(int argc, char **argv)
{
	t_global_data	p;

	if (init_global_data(argc, argv, &p) == false)
		return (error_message("invalid arguments"));
	philo(p);
	return (0);
}

bool	init_global_data(int argc, char **argv, t_global_data *p)
{
	if (!(argc == 5 || argc == 6))
		return (false);
	p->num_of_philo = ft_atoi(argv[1]);
	if (p->num_of_philo <= 0)
		return (false);
	p->time_to_die = ft_atoi(argv[2]);
	if (p->time_to_die < 0)
		return (false);
	p->time_to_eat = ft_atoi(argv[3]);
	if (p->time_to_eat < 0)
		return (false);
	p->time_to_sleep = ft_atoi(argv[4]);
	if (p->time_to_sleep < 0)
		return (false);
	if (argc == 6)
		p->num_of_must_eat = ft_atoi(argv[5]);
	else
		p->num_of_must_eat = -1;
	p->tid = malloc(sizeof(pthread_t) * p->num_of_philo);
	p->mutex = malloc(sizeof(pthread_mutex_t) * p->num_of_philo);
	if (!p->tid || !p->mutex)
		return (free_philo(p));
	return (true);
}
