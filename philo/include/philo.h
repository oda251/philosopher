/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:53:55 by yoda              #+#    #+#             */
/*   Updated: 2023/11/24 01:38:52 by yoda             ###   ########.fr       */
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

typedef long long		ms;
typedef struct timeval	t_time;
typedef struct s_philo
{
	int								philo_id;
	pthread_mutex_t					*m_meal;
	ms								last_eat;
	pthread_mutex_t					*m_end;
	bool							*end_flag;
	int								eat_count;
	int								time_to_eat;
	int								time_to_sleep;
	int								time_to_die;
	ms								starttime;
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
	bool							end_flag;
	t_philo							**philos;
	pthread_mutex_t					**fork;
	pthread_mutex_t					*m_end;
	pthread_mutex_t					**m_meal;
	ms								starttime;
}	t_global_data;
// -------------------init-------------------
bool				init_global_data(int argc, char **argv, t_global_data *p);
bool				init_philos(t_global_data p);
// -------------------philo-------------------
bool				philo(t_global_data p);
bool				eat(t_philo p, ms *time_ms);
bool				count_done(t_global_data p);
// -------------------utils-------------------
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
bool				ft_free(void *ptr);
bool				mutex_destroy(pthread_mutex_t **mutex, int num);
bool				two_mutex_destroy(pthread_mutex_t **mutex1,
						pthread_mutex_t **mutex2, int num);
bool				ft_free_two_val(void *ptr1, void *ptr2);
bool				ft_free_three_val(void *ptr1, void *ptr2, void *ptr3);
bool				ft_free_four_val(void *ptr1, void *ptr2, void *ptr3, void *ptr4);
bool				error_message(char *msg);
bool				put_status(ms time, int philo_id, char *status);
bool				ft_mutex_init(pthread_mutex_t *mutex, pthread_mutexattr_t *attr);
ms					convert_time(t_time time);
bool				get_mutex_bool(pthread_mutex_t *m, bool *b);
bool				is_dead(t_global_data *p, int i, ms time_ms);
bool				turn_true(pthread_mutex_t *m, bool *b);
bool				get_current_ms(ms *time_ms);

#endif