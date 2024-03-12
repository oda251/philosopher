/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:53:55 by yoda              #+#    #+#             */
/*   Updated: 2024/03/13 02:39:47 by yoda             ###   ########.fr       */
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
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# define TAKE_FORKS		1
# define EATING			2
# define SLEEPING		3
# define THINKING		4
# define DIED			5
# define SEM_WAITER		"/philo_waiter"
# define SEM_FORKS		"/philo_forks"
# define SEM_PRINT		"/philo_print"
# define SEM_FULL		"/philo_full"
# define SEM_UNIT_BASE	"/philo_unit_"

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
typedef struct s_shared_sems
{
	sem_t							*s_waiter;
	sem_t							*s_forks;
	sem_t							*s_print;
	sem_t							*s_full;
}	t_shared_sems;
typedef struct s_philosopher
{
	int								id;
	pid_t							pid;
	t_common_data					*common;
	char							*sem_name;
	sem_t							*s_last_eat;
	t_ms							last_eat;
	t_shared_sems					*sems;
	int								eat_count;
}	t_philosopher;
typedef struct s_data
{
	t_common_data					common;
	pid_t							*philos_pid;
	t_philosopher					*philos;
	t_shared_sems					sems;
	pid_t							full_monitor;
}	t_data;
// -------------------init-------------------
bool	validate_args(int argc, char **argv);
void	input_args(int argc, char **argv, t_common_data *common_data);
void	setup_data(t_data *data, t_common_data common, t_shared_sems *sems);
void	setup_philos(t_data *data);
// -------------------game-------------------
int		simulation(t_data *data);
void	*unit_philo(void *arg);
void	full_monitoring(t_data *data);
void	*unit_monitoring(void *arg);
// -------------------acts-------------------
void	act_eat(t_philosopher *p);
void	act_sleep(t_philosopher *p);
void	act_think(t_philosopher *p);
// -------------------utils-------------------
void	init_child_process(pid_t *pid, void (*func)(t_data *), t_data *data);
void	kill_all_philos(t_data *data);
void	main_exit(t_data *data, int status);
bool	error_message(char *msg);
bool	sem_create(sem_t **sem, char *name, int value);
bool	sem_kill(sem_t *sem, char *name);
int		get_sem_ms(sem_t *sem, t_ms *time);
void	set_sem_ms(sem_t *sem, t_ms *dest, t_ms val);
bool	put_status(sem_t *s_print,
			t_ms passed_time, int philo_id, int status);
t_ms	convert_time(t_time time);
bool	usleep_ms(t_ms time);
bool	get_current_ms(t_ms *time_ms);
bool	get_passed_time(t_common_data *common, t_ms *dest);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isdigit(int c);

#endif