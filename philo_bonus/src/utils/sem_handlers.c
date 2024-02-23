/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 03:19:25 by yoda              #+#    #+#             */
/*   Updated: 2024/02/23 19:23:57 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	sem_create(sem_t **sem, char *name, int value)
{
	sem_unlink(name);
	*sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (*sem == SEM_FAILED)
		return (error_message("sem_open error"));
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

int	get_sem_ms(sem_t *sem, t_ms *time)
{
	int	value;

	sem_wait(sem);
	value = *time;
	sem_post(sem);
	return (value);
}

void	set_sem_ms(sem_t *sem, t_ms *dest, t_ms val)
{
	sem_wait(sem);
	*dest = val;
	sem_post(sem);
}
