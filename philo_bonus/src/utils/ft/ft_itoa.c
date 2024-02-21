/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:16:27 by misuzuki          #+#    #+#             */
/*   Updated: 2024/02/21 13:46:28 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static char	*nb_put(char *result, long nb, int digit)
{
	size_t	muinus_flag;

	muinus_flag = 0;
	if (nb < 0)
	{
		nb = -nb;
		muinus_flag = 1;
	}
	digit--;
	while (digit >= 0)
	{
		if (digit == 0 && muinus_flag == 1)
			result[digit] = '-';
		else
			result[digit] = nb % 10 + '0';
		nb = nb / 10;
		digit--;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	long	nb;
	long	copy;
	size_t	digit;
	char	*result;

	nb = (long)n;
	digit = 1;
	copy = nb;
	if (nb < 0)
	{
		copy *= -1;
		digit++;
	}
	while (copy / 10 > 0)
	{
		digit++;
		copy = copy / 10;
	}
	result = ft_calloc(digit + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	return (nb_put(result, nb, digit));
}
