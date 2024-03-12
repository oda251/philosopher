/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:52:26 by yoda              #+#    #+#             */
/*   Updated: 2024/03/13 02:17:23 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		status;

	ft_bzero(&data, sizeof(t_data));
	if (validate_args(argc, argv) == false)
		return (error_message("invalid arguments"), EXIT_FAILURE);
	input_args(argc, argv, &(data.common));
	setup_data(&data, data.common, &data.sems);
	setup_philos(&data);
	status = simulation(&data);
	main_exit(&data, status);
	return (EXIT_FAILURE);
}
