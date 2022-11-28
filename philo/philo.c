/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:58:34 by fesper-s          #+#    #+#             */
/*   Updated: 2022/11/28 16:33:43 by fesper-s         ###   ########.fr       */
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
		data->philo[i].id = i;
		data->philo[i].fork_l = i;
		data->philo[i].fork_r = (i + 1) % data->nbphilo;
	}
	init_thread(data);
}

void	init_thread(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = data->philo;
	i = -1;
	while (++i < data->nbphilo)
		pthread_create(&data->philo[i].threads, NULL, &routine, \
			&philo[i]);
	i = -1;
	while (++i < data->nbphilo)
		pthread_join(philo[i].threads, NULL);
}

void	eating(t_data *data)
{
	printf("antes do lock\n");
	if (pthread_mutex_lock(&(data->forks[data->philo->fork_l])))
		printf("%d has taken a fork\n", data->philo->id);
}

void	*routine(void *p)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)p;
	data = philo->data;
	printf("%d\n", data->died);
	while (!data->died)
	{
		//eating(data);
	}
	return (NULL);
}
