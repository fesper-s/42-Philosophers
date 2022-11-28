/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:58:34 by fesper-s          #+#    #+#             */
/*   Updated: 2022/11/28 14:27:54 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	attr_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

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
	philo = data->philo;
	printf("%d\n", philo->data->ttdie);
	i = -1;
	while (++i < data->nbphilo)
	{
		printf("----------\nantes create\n");
		pthread_create(&data->philo[i].threads, NULL, &routine, \
			&philo[i]);
		printf("depois create\n----------\n");
	}
	i = -1;
	while (++i < data->nbphilo)
	{
		printf("antes do join\n");
		pthread_join(philo[i].threads, NULL);
		printf("depois do join\n");
	}
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
	(void) data;
	//printf("ROUTINE %d\n", data->ttdie);
	/*while (!data->died)
	{
		printf("no while\n");
		//eating(data);
	}*/
	return (NULL);
}