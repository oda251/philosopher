/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:54:54 by yoda              #+#    #+#             */
/*   Updated: 2023/11/24 01:48:00 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	end_philo(t_global_data p);

void	*unit_philo(void *arg)
{
	t_philo			p;
	ms				time_ms;

	p = *(t_philo *)arg;
	while (true)
	{
		if (eat(p, &time_ms) == false)
			return (false);
		if (get_mutex_bool(p.m_end, p.end_flag) == true)
		{
			pthread_mutex_unlock(p.left);
			pthread_mutex_unlock(p.right);
			return (NULL);
		}
		put_status(time_ms, p.philo_id, TAKE_FORKS);
		put_status(time_ms, p.philo_id, EATING);
		usleep(p.time_to_eat * 1000);
		pthread_mutex_unlock(p.left);
		pthread_mutex_unlock(p.right);
		if (get_current_ms(&time_ms) == false)
			return ("gettimeofday error\n");
		if (get_mutex_bool(p.m_end, p.end_flag) == true)
			return (NULL);
		if (put_status(time_ms, p.philo_id, SLEEPING) == false)
		usleep(p.time_to_sleep * 1000);
		if (get_current_ms(&time_ms) == false)
			return ("gettimeofday error\n");
		if (get_mutex_bool(p.m_end, p.end_flag) == true)
			return (NULL);
		if (put_status(time_ms, p.philo_id, THINKING) == false)
			return ("gettimeofday error\n");
	}
	return (NULL);
}

void	*monitoring(void	*arg)
{
	int					i;
	t_global_data		*p;
	ms					time_ms;

	p = (t_global_data *)arg;
	while (true)
	{
		usleep(100);
		if (get_current_ms(&time_ms) == false)
			return ("gettimeofday error\n");
		i = -1;
		while (++i < p->num_of_philo)
		{
			if (is_dead(p, i, time_ms) == true)
				break ;
		}
		if (count_done(*p) == true)
		{
			p->end_flag = true;
			break ;
		}
		if (get_mutex_bool(p->m_end, &(p->end_flag)) == true)
			break ;
	}
	return (NULL);
}

bool	philo(t_global_data p)
{
	int			i;
	t_time		starttime;
	pthread_t	m_tid;

	if (gettimeofday(&starttime, NULL) == -1)
		return (error_message("gettimeofday error\n"));
	p.starttime = convert_time(starttime);
	i = -1;
	while (++i < p.num_of_philo)
	{
		p.philos[i]->starttime = p.starttime;
		pthread_create(&(p.philos[i]->tid), NULL, unit_philo, p.philos[i]);
	}
	pthread_create(&m_tid, NULL, monitoring, &p);
	pthread_mutex_lock(p.m_end);
	p.end_flag = true;
	pthread_mutex_unlock(p.m_end);
	end_philo(p);
	return (true);
}

bool	end_philo(t_global_data p)
{
	int	i;

	i = -1;
	while (++i < p.num_of_philo)
	{
		pthread_join(p.philos[i]->tid, NULL);
		pthread_mutex_destroy(p.fork[i]);
	}
	ft_free_three_val(p.philos, p.fork, p.m_meal);
	return (true);
}
