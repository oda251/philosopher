/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:36:40 by yoda              #+#    #+#             */
/*   Updated: 2024/02/23 20:36:06 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	const size_t	sum = count * size;
	void			*dest;

	if (!size || !count)
	{
		dest = ft_calloc(1, 1);
		return (dest);
	}
	if (count > SIZE_MAX / size)
	{
		return (NULL);
	}
	dest = malloc(sum);
	if (!dest)
		return (NULL);
	ft_bzero(dest, sum);
	return (dest);
}
