/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:52:26 by yoda              #+#    #+#             */
/*   Updated: 2024/02/20 03:23:26 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (validate_args(argc, argv) == false)
		return (error_message("invalid arguments"), EXIT_FAILURE);
	input_args(argc, argv, &(data.common));
	if (setup_data(&data) == false)
		return (EXIT_FAILURE);
	if (setup_philos(&data) == false)
		return (EXIT_FAILURE);
	if (game(&data) == false)
		return (EXIT_FAILURE);
	free_data(&data, -1);
	return (EXIT_SUCCESS);
}
