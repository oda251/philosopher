/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:52:26 by yoda              #+#    #+#             */
/*   Updated: 2023/11/29 17:48:10 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_global_data(int argc, char **argv, t_global_data *p);
bool	case_one_philo(t_global_data p);

int	main(int argc, char **argv)
{
	t_global_data	p;
	bool			result;

	if (init_global_data(argc, argv, &p) == false)
		return (error_message("invalid arguments"));
	init_philos(p);
	if (p.num_of_philo == 1)
		result = case_one_philo(p);
	else
		result = philo(p);
	if (result == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool	case_one_philo(t_global_data p)
{
	if (get_current_ms(&p.starttime) == false)
		return (false);
	usleep(p.time_to_die * 1000);
	put_status(p.starttime, 1, DIED);
	return (true);
}