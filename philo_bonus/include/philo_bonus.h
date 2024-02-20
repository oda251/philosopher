/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:53:55 by yoda              #+#    #+#             */
/*   Updated: 2024/02/21 02:54:08 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>
# include <signal.h>
# include <string.h>
# include <limits.h>
# define TAKE_FORKS		"has taken a fork"
# define EATING			"is eating"
# define SLEEPING		"is sleeping"
# define THINKING		"is thinking"
# define DIED			"died"
# define SEM_WAITER		"/philo_waiter"
# define SEM_FORKS		"/philo_forks"
# define SEM_PRINT		"/philo_print"
# define SEM_FULL		"/philo_full"
# define SEM_UNIT_BASE	"/philo_unit_"
# define SEM_DEAD		"/philo_dead"


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
	pid_t							pid;
	t_common_data					*common;
	char							*sem_name;
	sem_t							*s_last_eat;
	t_ms							last_eat;
	sem_t							*s_waiter;
	sem_t							*s_forks;
	sem_t							*s_print;
	sem_t							*s_full;
	sem_t							*s_dead;
	tid_t							death_monitor;
}	t_philosopher;
typedef struct s_data
{
	t_common_data					common;
	pid_t							*philos_pid;
	t_philosopher					*philos;
	sem_t							*s_waiter;
	sem_t							*s_forks;
	sem_t							*s_print;
	sem_t							*s_full;
	sem_t							*s_dead;
	tid_t							death_monitor;
	tid_t							full_monitor;
}	t_data;
// -------------------init-------------------
bool	validate_args(int argc, char **argv);
void	input_args(int argc, char **argv, t_common_data *common_data);
void	setup_data(t_data *data, t_common_data common);
void	setup_philos(t_data *data);
// -------------------game-------------------
bool	game(t_data *data);
void	*unit_philo(void *arg);
void	*monitoring(void *arg);
// -------------------acts-------------------
bool	act_eat(t_philosopher *p);
bool	act_sleep(t_philosopher *p);
bool	act_think(t_philosopher *p);
// -------------------utils-------------------
bool	sem_create(sem_t *sem, char *name, int value);
bool	sem_kill(sem_t *sem, char *name);
void	kill_all_philos(t_data *data);
void	main_exit(t_data *data, int status);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
bool	error_message(char *msg);
void	free_data(t_data *data, int setup_progress);
bool	put_status(pthread_mutex_t *m_print,
			t_ms passed_time, int philo_id, char *status);
t_ms	convert_time(t_time time);
void	usleep_ms(t_ms time);
bool	get_current_ms(t_ms *time_ms);
bool	get_passed_time(t_common_data *common, t_ms *dest);
bool	put_status_if_not_end(t_philosopher *p, t_ms passed_time, char *status);

#endif