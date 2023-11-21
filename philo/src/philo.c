/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:54:54 by yoda              #+#    #+#             */
/*   Updated: 2023/11/22 02:23:26 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	end_philo(t_global_data p); 

void	*unit_philo(void *arg)
{
	t_philo			p;
	t_time			time;
	suseconds_t	time_ms;

	p = *(t_philo *)arg;
	while (true)
	{
		if (eat(p, &time_ms) == false)
			return (false);
		if (get_mutex_bool(p.m_end, &(p.end_flag)) == true)
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
		if (put_status(-1, p.philo_id, SLEEPING) == false)
			return ("gettimeofday error\n");
		usleep(p.time_to_sleep * 1000);
		if (put_status(-1, p.philo_id, THINKING) == false)
			return ("gettimeofday error\n");
	}
	return (NULL);
}

bool	monitoring(void	*arg)
{
	int					i;
	t_global_data		*p;
	t_time				time;
	suseconds_t			time_ms;

	p = (t_global_data *)arg;
	while (true)
	{
		if (gettimeofday(&time, NULL) == -1)
			return (error_message("gettimeofday error\n"));
		time_ms = convert_time(time);
		i = -1;
		while (++i < p->num_of_philo)
		{
			if (is_dead(*p, i, time_ms) == true)
			{
				turn_true(p->m_end, &(p->end_flag));
				put_status(time_ms, i, DIED);
				break ;
			}
		}
		if (check_num_of_meals(*p) == true)
			return (true);
	}
}

bool	philo(t_global_data p)
{
	int			i;
	t_time	starttime;

	i = -1;
	while (++i < p.num_of_philo)
	{
		if (pthread_mutex_init(p.fork[i], NULL))
			return (error_message("mutex_init error\n"));
	}
	if (gettimeofday(&starttime, NULL) == -1)
		return (error_message("gettimeofday error\n"));
	i = -1;
	while (++i < p.num_of_philo)
	{
		if (init_philo(p, i) == false)
			return (error_message("mutex_init error\n"));
		pthread_create(&(p.philos[i].tid), NULL, unit_philo, &(p.philos[i]));
	}
	pthread_create(&(p.philos[0].tid), NULL, monitoring, &p);
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
		pthread_join(p.philos[i].tid, NULL);
		pthread_mutex_destroy(p.fork[i]);
	}
	ft_free_two_val(p.philos, p.fork);
	return (true);
}
