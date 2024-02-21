/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:08:54 by yoda              #+#    #+#             */
/*   Updated: 2024/02/21 14:49:41 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	setup_data(t_data *data, t_common_data common, t_shared_sems *sems)
{
	data->philos_pid = ft_calloc(
			common.num_of_philos, sizeof(pid_t));
	if (!data->philos_pid)
	{
		error_message("malloc error\n");
		exit(EXIT_FAILURE);
	}
	if (!sem_create(&(sems->s_print), SEM_PRINT, 1))
		main_exit(data, EXIT_FAILURE);
	if (!sem_create(&(sems->s_forks), SEM_FORKS, common.num_of_philos))
		main_exit(data, EXIT_FAILURE);
	if (!sem_create(&(sems->s_full), SEM_FULL, 0))
		main_exit(data, EXIT_FAILURE);
	if (!sem_create(&(sems->s_waiter), SEM_WAITER, common.num_of_philos / 2))
		main_exit(data, EXIT_FAILURE);
}
