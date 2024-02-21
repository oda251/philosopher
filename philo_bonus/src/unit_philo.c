/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 08:16:44 by yoda              #+#    #+#             */
/*   Updated: 2024/02/21 14:31:56 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*unit_philo(void *arg)
{
	t_philosopher	*philo;
	pthread_t		monitor;

	philo = (t_philosopher *)arg;
	if (pthread_create(&monitor, NULL, unit_monitoring, philo) != 0)
	{
		error_message("pthread_create error\n");
		exit(EXIT_FAILURE);
	}
	while (true)
	{
		act_eat(philo);
		act_sleep(philo);
		act_think(philo);
	}
	return (NULL);
}
