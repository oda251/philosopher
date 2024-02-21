/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:58:47 by yoda              #+#    #+#             */
/*   Updated: 2024/02/21 13:24:25 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	error_header(void)
{
	write(2, "Error: ", 7);
}

bool	error_message(char *msg)
{
	error_header();
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (false);
}
