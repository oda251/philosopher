/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:52:26 by yoda              #+#    #+#             */
/*   Updated: 2024/02/21 02:48:37 by yoda             ###   ########.fr       */
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
	setup_data(&data, data.common);
	setup_philos(&data);
	if (game(&data) == false)
		main_exit(&data, EXIT_FAILURE);
	main_exit(&data, EXIT_SUCCESS);
	return (EXIT_SUCCESS);		
}
