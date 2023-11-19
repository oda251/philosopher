/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:30:19 by yoda              #+#    #+#             */
/*   Updated: 2023/11/19 19:18:43 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_UTILS_H
# define PHILO_UTILS_H
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	ft_free(void *ptr);
bool	error_message(char *msg);

#endif