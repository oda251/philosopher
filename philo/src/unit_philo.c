/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 08:16:44 by yoda              #+#    #+#             */
/*   Updated: 2024/03/26 17:15:57 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*unit_philo(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	wait_start(philo->common);
	while (true)
	{
		if (act_eat(philo) == false)
			return (NULL);
		if (act_sleep(philo) == false)
			return (NULL);
		if (act_think(philo) == false)
			return (NULL);
	}
	return (NULL);
}
