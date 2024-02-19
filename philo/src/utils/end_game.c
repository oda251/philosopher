/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 08:35:29 by yoda              #+#    #+#             */
/*   Updated: 2024/02/20 02:51:43 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_game_unit(t_philosopher *philo)
{
	set_mutex_int(
		philo->m_end_flag,
		philo->end_flag,
		philo->common->num_of_philos
		);
}

void	end_game(t_data *data)
{
	set_mutex_int(
		&(data->m_end_flag),
		&(data->end_flag),
		data->common.num_of_philos
		);
}
