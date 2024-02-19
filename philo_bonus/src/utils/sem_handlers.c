/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:31:58 by yoda              #+#    #+#             */
/*   Updated: 2024/02/19 21:16:46 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*create_new_sem(char *name, int value)
{
	sem_t	*sem;

	sem_unlink(name);
	sem = sem_open(name, O_CREAT, 0644, value);
	if (sem == SEM_FAILED)
		exit_with_message("sem_open error\n");
	return (sem);
}
