/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:08:54 by yoda              #+#    #+#             */
/*   Updated: 2024/02/21 14:49:52 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static char	*get_sem_name(char *base, int id)
{
	char	*name;
	char	*id_str;

	id_str = ft_itoa(id);
	if (!id_str)
		return (NULL);
	name = ft_strjoin(base, id_str);
	free(id_str);
	if (!name)
		return (NULL);
	return (name);
}

static void	setup_philo(t_data *data, t_philosopher *philo, int i)
{
	philo->sem_name = get_sem_name(SEM_UNIT_BASE, i + 1);
	if (!philo->sem_name)
	{
		error_message("malloc error\n");
		main_exit(data, EXIT_FAILURE);
	}
	if (!sem_create(&(philo->s_last_eat), philo->sem_name, 1))
			main_exit(data, EXIT_FAILURE);
	philo->id = i + 1;
	philo->common = &(data->common);
	philo->sems = &(data->sems);
}

void	setup_philos(t_data *data)
{
	int	i;

	data->philos = ft_calloc(data->common.num_of_philos, sizeof(t_philosopher));
	if (!data->philos)
	{
		error_message("malloc error\n");
		main_exit(data, EXIT_FAILURE);
	}
	i = 0;
	while (i < data->common.num_of_philos)
	{
		setup_philo(data, &(data->philos[i]), i);
		i++;
	}
}
