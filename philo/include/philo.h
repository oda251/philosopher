/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:53:55 by yoda              #+#    #+#             */
/*   Updated: 2024/02/18 09:56:55 by yoda             ###   ########.fr       */
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
typedef struct s_philosopher
{
	int								id;
	t_common_data					*common;
	pthread_mutex_t					m_last_eat;
	ms								last_eat;
	int								eat_count;
	pthread_mutex_t					*left_fork;
	pthread_mutex_t					*right_fork;
	pthread_mutex_t					*m_end_flag;
	int								*end_flag;
}	t_philosopher;

typedef struct s_monitor
{
	pthread_mutex_t					m_end_flag;
	int								end_flag;
}	t_monitor;

typedef struct s_common_data
{
	ms								starttime;
	int								num_of_philos;
	int								time_to_eat;
	int								time_to_sleep;
	int								time_to_die;
	int								times_to_eat;
}	t_common_data;

typedef struct s_data
{
	t_common_data					common;
	t_monitor						monitor;
	pthread_t						monitor_tid;
	pthread_t						*tid;
	t_philosopher					*philos;
	pthread_mutex_t					*forks;
}	t_data;
// -------------------init-------------------
bool	validate_args(int argc, char **argv);
void	input_args(int argc, char **argv, t_common_data *common_data);
bool	setup_data(t_data *data);
bool	setup_philos(t_data *data);
// -------------------game-------------------
bool	game(t_data *data);
void	*unit_philo(void *arg);
void	*monitoring(void *arg);
// -------------------acts-------------------
bool	eat(t_philosopher *p);
bool	sleep(t_philosopher *p);
bool	think(t_philosopher *p);
// -------------------utils-------------------
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
bool	mutex_init(pthread_mutex_t *mutex);
bool	get_mutex_bool(pthread_mutex_t *m, bool *buf);
bool	get_mutex_int(pthread_mutex_t *m, int *buf);
ms		get_mutex_ms(pthread_mutex_t *m, ms *buf);
void	set_mutex_int(pthread_mutex_t *m, int *buf, int val);
void	set_mutex_bool(pthread_mutex_t *m, bool *buf, bool val);
void	set_mutex_ms(pthread_mutex_t *m, ms *buf, ms val);
void	end_game(t_data *data);
void	end_game_unit(t_philosopher *philo);
bool	error_message(char *msg);
void	free_data(t_data *data, int setup_progress);
bool	put_status(ms passed_time, int philo_id, char *status);
ms		convert_time(t_time time);
void	usleep_ms(ms time);
bool	get_current_ms(ms *time_ms);
bool	get_passed_time(t_common_data *common, ms *dest);
bool	is_dead(t_data *data, int i, ms time);

#endif