/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:28:13 by yoda              #+#    #+#             */
/*   Updated: 2023/11/21 03:40:18 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static int	ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

static int	solve(const char *str)
{
	unsigned long	num;
	unsigned long	tmp;

	num = 0;
	while (ft_isdigit(*str))
	{
		tmp = num;
		num = num * 10 + (*str - '0');
		if (num >= (unsigned long) LONG_MAX || tmp > num)
			return ((int) LONG_MAX);
		str++;
	}
	if (*str)
		return (-1);
	return (num);
}

int	ft_atoi(const char *str)
{
	if (!*str || !(*str == '+' || ft_isdigit(*str)))
		return (-1);
	if (*str == '+')
		str++;
	return (solve(str));
}
