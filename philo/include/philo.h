/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:53:55 by yoda              #+#    #+#             */
/*   Updated: 2023/11/22 02:22:27 by yoda             ###   ########.fr       */
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
# define TAKE_FORKS	"has taken a fork"
# define EATING		"is eating"
# define SLEEPING	"is sleeping"
# define THINKING	"is thinking"
# define DIED		"died"

typedef struct timeval	t_time;
typedef struct s_philo
{
	int								philo_id;
	pthread_mutex_t					*m_meal;
	suseconds_t						last_eat;
	pthread_mutex_t					*m_end;
	bool							*end_flag;
	int								eat_count;
	int								time_to_eat;
	int								time_to_sleep;
	int								time_to_die;
	t_time							starttime;
	pthread_t						tid;
	pthread_mutex_t					*left;
	pthread_mutex_t					*right;
	bool							done;
}	t_philo;
typedef struct s_global_data
{
	int								num_of_philo;
	int								time_to_die;
	int								time_to_eat;
	int								time_to_sleep;
	int								num_of_must_eat;
	t_philo							**philos;
	pthread_mutex_t					**fork;
	pthread_mutex_t					*m_end;
	bool							end_flag;
	t_time							starttime;
}	t_global_data;
// -------------------init-------------------
bool				init_global_data(int argc, char **argv, t_global_data *p);
bool				init_philo(t_global_data p, int count);
// -------------------philo-------------------
bool				philo(t_global_data p);
bool				eat(t_philo p, t_time *time)
bool				check_num_of_meals(t_global_data p);
// -------------------utils-------------------
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
bool				ft_free(void *ptr);
bool				ft_free_two_val(void *ptr1, void *ptr2);
bool				error_message(char *msg);
bool				put_status(suseconds_t time, int philo_id, char *status);
bool				ft_mutex_init(pthread_mutex_t *mutex, pthread_mutexattr_t *attr);
long long			convert_time(t_time time);
bool				get_mutex_bool(pthread_mutex_t *m, bool *b);
bool				is_dead(t_global_data p, int i, suseconds_t time_ms);
bool				turn_true(pthread_mutex_t *m, bool *b);

#endif