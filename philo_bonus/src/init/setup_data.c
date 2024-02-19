/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:08:54 by yoda              #+#    #+#             */
/*   Updated: 2024/02/19 20:33:46 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	setup_data(t_data *data)
{
	int	i;

	data->sem_forks = create_new_sem(SEM_FORKS, data->common.num_of_philos);
	data->sem_full = create_new_sem(SEM_FULL, data->common.num_of_philos);
	return (true);
}
