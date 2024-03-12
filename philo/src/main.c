/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:52:26 by yoda              #+#    #+#             */
/*   Updated: 2024/03/13 02:43:00 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (validate_args(argc, argv) == false)
		return (error_message("invalid arguments"), EXIT_FAILURE);
	input_args(argc, argv, &(data.common));
	if (data.common.num_of_philos == 1)
	{
		if (usleep_ms(data.common.time_to_die) == false)
			return (free_data(&data, -1), EXIT_FAILURE);
		printf("%d 1 %s\n", data.common.time_to_die, "died");
		free_data(&data, -1);
		return (EXIT_SUCCESS);
	}
	if (setup_data(&data) == false)
		return (EXIT_FAILURE);
	if (setup_philos(&data) == false)
		return (EXIT_FAILURE);
	if (game(&data) == false)
		return (EXIT_FAILURE);
	free_data(&data, -1);
	return (EXIT_SUCCESS);
}
