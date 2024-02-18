/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 08:16:44 by yoda              #+#    #+#             */
/*   Updated: 2024/02/18 09:28:42 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*unit_philo(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (true)
	{
		if (eat(philo) == false)
			return (NULL);
		if (sleep(philo) == false)
			return (NULL);
		if (think(philo) == false)
			return (NULL);
	}
	return (NULL);
}
