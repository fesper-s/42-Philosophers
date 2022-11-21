/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:13:21 by fesper-s          #+#    #+#             */
/*   Updated: 2022/11/21 10:38:10 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_data
{
	int				nbphilo;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				nbmeals;
	pthread_mutex_t	*forks;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo
{
	int			id;
	int			fork_l;
	int			fork_r;
	pthread_t	threads;
	t_data		*data;
}	t_philo;

// main.c
void	get_arg(t_data *data, char **str, int size);
void	*routine(void *p);
void	attr_philo(t_data *data);
// utils.c
int		ft_isdigit(int n);
int		ft_atoi(const char *str);

#endif