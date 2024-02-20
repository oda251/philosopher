/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:08:54 by yoda              #+#    #+#             */
/*   Updated: 2024/02/21 02:37:55 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	setup_data(t_data *data, t_common_data common)
{
	int		i;
	char	*tmp;
	bool	res;

	data->philos_pid = ft_calloc(
			common.num_of_philos, sizeof(pid_t));
	if (!data->philos_pid)
	{
		error_message("malloc error\n");
		exit(EXIT_FAILURE);
	}
	res = create_sem(&(data->s_print), SEM_PRINT, 1);
	res = res && create_sem(&(data->s_forks), SEM_FORKS, common.num_of_philos);
	res = res && create_sem(&(data->s_full), SEM_FULL, 0);
	res = res && create_sem(&(data->s_waiter), SEM_WAITER, common.num_of_philos / 2);
	res = res && create_sem(&(data->s_dead), SEM_DEAD, 1);
	if (!res)
	{
		error_message("sem_open error\n");
		main_exit(EXIT_FAILURE);
	}
}
