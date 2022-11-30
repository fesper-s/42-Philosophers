/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:13:21 by fesper-s          #+#    #+#             */
/*   Updated: 2022/11/30 09:38:41 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				nbphilo;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				nbmeals;
	int				died;
	unsigned long	time;
	pthread_mutex_t	*forks;
	pthread_mutex_t writing;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				fork_l;
	int				fork_r;
	unsigned long	last_meal;
	pthread_t		threads;
	t_data			*data;
}	t_philo;

// main.c
int				get_arg(t_data *data, char **str, int size);
// philo.c
void			attr_philo(t_data *data);
void			init_thread(t_data *data);
void			*routine(void *p);
// time.c
unsigned long	start_count(void);
// mutex.c
void			init_mutex(t_data *data);
void			destroy_mutex(t_data *data);
void			print_msg(char *str, t_data *data, int id);
void			eating(t_philo *philo);
// utils.c
int				ft_isdigit(int n);
int				t_strlen(char *str);
void			ft_putstr_fd(char *str, int fd);
int				ft_atoi(const char *str);

#endif