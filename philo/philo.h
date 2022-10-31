/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:13:21 by fesper-s          #+#    #+#             */
/*   Updated: 2022/10/31 09:28:25 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int	nbphilo;
	int	ttdie;
	int	tteat;
	int	ttsleep;
	int	nbmeals;
}	t_philo;

//main.c
void	get_arg(t_philo *stats, char **str, int size);
// utils.c
int		ft_isdigit(int n);
int		ft_atoi(const char *str);

#endif