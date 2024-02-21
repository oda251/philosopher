/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_chilid_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:38:13 by yoda              #+#    #+#             */
/*   Updated: 2024/02/21 13:15:17 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_child_process(pid_t *pid, void (*func)(t_data *), t_data *data)
{
	*pid = fork();
	if (*pid == -1)
	{
		kill_all_philos(data);
		error_message("fork error\n");
		main_exit(data, EXIT_FAILURE);
	}
	else if (*pid == 0)
		(*func)(data);
}
