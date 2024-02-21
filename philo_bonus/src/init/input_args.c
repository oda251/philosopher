/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:08:54 by yoda              #+#    #+#             */
/*   Updated: 2024/02/21 13:32:35 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	input_args(int argc, char **argv, t_common_data *common_data)
{
	common_data->num_of_philos = ft_atoi(argv[1]);
	common_data->time_to_die = ft_atoi(argv[2]);
	common_data->time_to_eat = ft_atoi(argv[3]);
	common_data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		common_data->times_to_eat = ft_atoi(argv[5]);
	else
		common_data->times_to_eat = -1;
}
