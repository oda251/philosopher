/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:53:55 by yoda              #+#    #+#             */
/*   Updated: 2024/03/21 18:10:36 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>
# define TAKE_FORKS	1
# define EATING		2
# define SLEEPING	3
# define THINKING	4
# define DIED		5

typedef long long		t_ms;
typedef struct timeval	t_time;
typedef struct s_common_data
{
	t_ms							starttime;
	int								num_of_philos;
	int								time_to_eat;
	int								time_to_sleep;
	int								time_to_die;
	int								times_to_eat;
}	t_common_data;
typedef struct s_philosopher
{
	int								id;
	t_common_data					*common;
	pthread_mutex_t					*m_last_eat;
	t_ms							last_eat;
	int								eat_count;
	pthread_mutex_t					*left_fork;
	pthread_mutex_t					*right_fork;
	pthread_mutex_t					*m_end_flag;
	int								*end_flag;
	pthread_mutex_t					*m_print;
	pthread_mutex_t					*m_waiter;
}	t_philosopher;
typedef struct s_data
{
	t_common_data					common;
	pthread_mutex_t					m_print;
	pthread_t						monitor_tid;
	pthread_t						floor_tid;
	pthread_t						*waiter_tid;
	pthread_t						*tid;
	t_philosopher					*philos;
	pthread_mutex_t					*forks;
	pthread_mutex_t					*waiters;
	pthread_mutex_t					m_end_flag;
	int								end_flag;
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
void	*floor_(void *arg);
// -------------------acts-------------------
bool	act_eat(t_philosopher *p);
bool	act_sleep(t_philosopher *p);
bool	act_think(t_philosopher *p);
// -------------------utils-------------------
void	ft_bzero(void *s, size_t n);
int		ft_isdigit(int c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
bool	mutex_init(pthread_mutex_t *mutex);
bool	get_mutex_bool(pthread_mutex_t *m, bool *buf);
int		get_mutex_int(pthread_mutex_t *m, int *buf);
t_ms	get_mutex_ms(pthread_mutex_t *m, t_ms *buf);
void	set_mutex_int(pthread_mutex_t *m, int *buf, int val);
void	set_mutex_bool(pthread_mutex_t *m, bool *buf, bool val);
void	set_mutex_ms(pthread_mutex_t *m, t_ms *buf, t_ms val);
void	end_game(t_data *data);
bool	end_game_unit(t_philosopher *philo, char *message);
bool	error_message(char *msg);
void	free_data(t_data *data, int setup_progress);
bool	put_status(t_philosopher *p, int status);
t_ms	convert_time(t_time time);
bool	usleep_ms(t_ms time);
bool	get_current_ms(t_ms *time_ms);
bool	get_passed_time(t_common_data *common, t_ms *dest);
bool	wait_start(t_common_data *common);

#endif