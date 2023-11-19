/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:15:36 by yoda              #+#    #+#             */
/*   Updated: 2023/11/19 19:16:08 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

void	ft_free(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
	ptr = NULL;
}
