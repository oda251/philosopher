/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 03:19:25 by yoda              #+#    #+#             */
/*   Updated: 2024/02/20 03:57:45 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	sem_create(sem_t *sem, char *name, int value)
{
	sem_unlink(name);
	sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (sem == SEM_FAILED)
		return (false);
	return (true);
}

bool	sem_kill(sem_t *sem, char *name)
{
	if (sem == SEM_FAILED)
		return (true);
	if (sem_close(sem) == -1)
		return (false);
	if (sem_unlink(name) == -1)
		return (false);
	return (true);
}