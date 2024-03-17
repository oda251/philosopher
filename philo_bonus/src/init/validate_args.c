/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:08:54 by yoda              #+#    #+#             */
/*   Updated: 2024/03/17 21:11:28 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	is_positive_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	validate_args(int argc, char **argv)
{
	int	i;

	if (!(argc == 5 || argc == 6))
		return (false);
	i = 1;
	while (i < argc)
	{
		if (is_positive_number(argv[i]) == false)
			return (false);
		i++;
	}
	if (ft_atoi(argv[1]) < 1 || 200 < ft_atoi(argv[1]))
		return (false);
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return (false);
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (false);
	return (true);
}
