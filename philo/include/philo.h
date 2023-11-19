/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:53:55 by yoda              #+#    #+#             */
/*   Updated: 2023/11/19 22:46:56 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>
# include "philo_utils.h"
# define TAKE_FORK	"has taken a fork"
# define EATING		"is eating"
# define SLEEPING	"is sleeping"
# define THINKING	"is thinking"
# define DIED		"died"

typedef struct timeval	t_time;
typedef struct s_global_data
{
	int					num_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_of_must_eat;
	int					philo_id;
	pthread_t			*tid;
	pthread_mutex_t		*mutex;
	t_time				starttime;
}	t_global_data;
void	philo(t_global_data p);
bool	free_philo(t_global_data *p);
bool	put_status(suseconds_t start, int philo_id, char *status);

#endif