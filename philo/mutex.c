/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:57:37 by fesper-s          #+#    #+#             */
/*   Updated: 2022/11/29 09:44:04 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbphilo);
	i = -1;
	while (++i < data->nbphilo)
		pthread_mutex_init(&(data->forks[i]), NULL);
}

void	destroy_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbphilo)
		pthread_mutex_destroy(&(data->forks[i]));
}
