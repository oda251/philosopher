/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:15:36 by yoda              #+#    #+#             */
/*   Updated: 2023/11/21 03:40:38 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_free(void *ptr)
{
	if (!ptr)
		return (false);
	free(ptr);
	return (false);
}

bool	ft_free_two_val(void *ptr1, void *ptr2)
{
	ft_free(ptr1);
	ft_free(ptr2);
	return (false);
}