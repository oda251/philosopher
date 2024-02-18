/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:08:54 by yoda              #+#    #+#             */
/*   Updated: 2024/02/18 10:18:46 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	validate_args(int argc, char **argv)
{
	if (!(argc == 5 || argc == 6))
		return (false);
	if (ft_atoi(argv[1]) < 1)
		return (false);
	if (ft_atoi(argv[2]) < 10 || ft_atoi(argv[3]) < 10 || ft_atoi(argv[4]) < 10)
		return (false);
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (false);
	return (true);
}
