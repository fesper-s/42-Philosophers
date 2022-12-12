/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:58:34 by fesper-s          #+#    #+#             */
/*   Updated: 2022/12/12 09:17:53 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	attr_philo(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * data->nbphilo);
	data->died = 0;
	i = -1;
	while (++i < data->nbphilo)
	{
		data->philo[i].data = data;
		data->philo[i].id = i + 1;
		data->philo[i].fork_l = i;
		data->philo[i].fork_r = (i + 1) % data->nbphilo;
		data->philo[i].meals = 0;
	}
	init_thread(data);
}

void	init_thread(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = data->philo;
	data->time = start_count();
	i = -1;
	while (++i < data->nbphilo)
	{
		pthread_create(&data->philo[i].threads, NULL, &routine, \
			&philo[i]);
		pthread_mutex_lock(&(data->ate));
		philo[i].last_meal = start_count();
		pthread_mutex_unlock(&(data->ate));
	}
	i = -1;
	check_health(data, philo);
	while (++i < data->nbphilo)
		pthread_join(philo[i].threads, NULL);
}

void	*routine(void *p)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)p;
	data = philo->data;
	if (philo->id % 2 != 0)
		usleep(15000);
	while (1)
	{	
		pthread_mutex_lock(&(data->ate));
		pthread_mutex_lock(&(data->writing));
		if (data->philos_ate == data->nbphilo || data->died == 1)
		{
			pthread_mutex_unlock(&(data->ate));
			pthread_mutex_unlock(&(data->writing));
			break ;
		}
		pthread_mutex_unlock(&(data->ate));
		pthread_mutex_unlock(&(data->writing));
		eating(philo);
	}
	return (NULL);
}
