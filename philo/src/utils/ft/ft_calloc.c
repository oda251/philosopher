/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:16:46 by misuzuki          #+#    #+#             */
/*   Updated: 2024/02/18 05:51:01 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (size > SIZE_MAX / count)
		return (NULL);
	str = malloc(count * size);
	if (str == NULL)
		return (NULL);
	str = ft_memset(str, 0, count * size);
	return (str);
}
