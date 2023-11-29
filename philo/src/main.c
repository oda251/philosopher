/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:52:26 by yoda              #+#    #+#             */
/*   Updated: 2023/11/29 17:26:49 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_global_data(int argc, char **argv, t_global_data *p);

int	main(int argc, char **argv)
{
	t_global_data	p;
	bool			result;

	if (init_global_data(argc, argv, &p) == false)
		return (error_message("invalid arguments"));
	init_philos(p);
	result = philo(p);
	if (result == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
