/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:52:26 by yoda              #+#    #+#             */
/*   Updated: 2023/11/24 01:15:32 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_global_data(int argc, char **argv, t_global_data *p);

int	main(int argc, char **argv)
{
	t_global_data	p;

	if (init_global_data(argc, argv, &p) == false)
		return (error_message("invalid arguments"));
	init_philos(p);
	if (philo(p) == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
