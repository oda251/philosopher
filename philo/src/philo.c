/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:54:54 by yoda              #+#    #+#             */
/*   Updated: 2023/11/29 19:19:38 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	end_philo(t_global_data p, pthread_t m_tid);

void	*unit_philo(void *arg)
{
	t_philo			*p;

	printf("unit_philo\n");
	p = (t_philo *)arg;
	while (true)
	{
		if (start_eating(p) == false)
			return (false);
		if (get_mutex_bool(p->data->m_end, &(p->data->end_flag)) == true)
		{
			pthread_mutex_unlock(p->left);
			pthread_mutex_unlock(p->right);
			return (NULL);
		}
		put_status(p->data->starttime, p->philo_id, TAKE_FORKS);
		put_status(p->data->starttime, p->philo_id, EATING);
		usleep(p->data->time_to_eat * 1000);
		pthread_mutex_unlock(p->left);
		pthread_mutex_unlock(p->right);
		if (get_mutex_bool(p->data->m_end, &(p->data->end_flag)) == true)
			return (NULL);
		if (put_status(p->data->starttime, p->philo_id, SLEEPING) == false)
		usleep(p->data->time_to_sleep * 1000);
		if (get_mutex_bool(p->data->m_end, &(p->data->end_flag)) == true)
			return (NULL);
		if (put_status(p->data->starttime, p->philo_id, THINKING) == false)
			return ("gettimeofday error\n");
	}
	return (NULL);
}

void	*monitoring(void	*arg)
{
	int					i;
	t_global_data		*p;

	printf("moni\n");
	p = (t_global_data *)arg;
	while (true)
	{
		i = -1;
		while (++i < p->num_of_philo)
		{
			if (is_dead(p, i) == true)
			{
				turn_true(p->m_end, &p->end_flag);
				return (NULL);
			}
		}
		if (count_done(*p) == true)
		{
			turn_true(p->m_end, &p->end_flag);
			return (NULL);
		}
		usleep(200);
	}
	return (NULL);
}

bool	philo(t_global_data p)
{
	int			i;
	pthread_t	m_tid;

	if (get_current_ms(&(p.starttime)) == false)
		return (false);
	i = -1;
	while (++i < p.num_of_philo)
	{
		p.philos[i]->last_eat = p.starttime;
		pthread_create(&(p.philos[i]->tid), NULL, unit_philo, p.philos[i]);
	}
	pthread_create(&m_tid, NULL, monitoring, &p);
	end_philo(p, m_tid);
	return (true);
}

bool	end_philo(t_global_data p, pthread_t m_tid)
{
	int	i;

	pthread_join(m_tid, NULL);
	i = -1;
	while (++i < p.num_of_philo)
		pthread_join(p.philos[i]->tid, NULL);
	pthread_mutex_destroy(p.m_end);
	mutex_destroy(p.forks, p.num_of_philo);
	mutex_destroy(p.m_meals, p.num_of_philo);
	ft_free_three_val(p.philos, p.forks, p.m_meals);
	return (true);
}
