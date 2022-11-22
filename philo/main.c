/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:16:42 by fesper-s          #+#    #+#             */
/*   Updated: 2022/11/22 11:31:49 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_arg(t_data *data, char **str, int size)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	data->nbphilo = ft_atoi(str[1]);
	data->ttdie = ft_atoi(str[2]);
	data->tteat = ft_atoi(str[3]);
	data->ttsleep = ft_atoi(str[4]);
	if (size == 6)
		data->nbmeals = ft_atoi(str[5]);
}

void	check_philo(t_data *data, int size)
{
	printf("Number of Philosophers: %d\n", data->nbphilo);
	printf("Time to die: %d\n", data->ttdie);
	printf("Time to eat: %d\n", data->tteat);
	printf("Time to sleep: %d\n", data->ttsleep);
	if (size == 6)
		printf("Number of meals: %d\n", data->nbmeals);
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
	printf("%d\n", data->ttdie);
	/*while (!data->died)
	{
		printf("no while\n");
		//eating(data);
	}*/
	return (NULL);
}

void	init_mutex(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbphilo);
	i = -1;
	while (++i < data->nbphilo)
		pthread_mutex_init(&(data->forks[i]), NULL);
}

void	attr_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	data->philo = malloc(sizeof(t_philo) * data->nbphilo);
	data->died = 0;
	i = -1;
	while (++i < data->nbphilo)
	{
		data->philo[i].id = i;
		data->philo[i].fork_l = i;
		data->philo[i].fork_r = (i + 1) % data->nbphilo;
	}
	philo = data->philo;
	printf("%d\n", philo->data->ttdie);
	i = -1;
	while (++i < data->nbphilo)
	{
		printf("antes create\n");
		pthread_create(&data->philo[i].threads, NULL, &routine, \
			&philo[i]);
		printf("depois create\n");
	}
	i = -1;
	while (++i < data->nbphilo)
	{
		printf("antes do join\n");
		pthread_join(philo[i].threads, NULL);
		printf("depois do join\n");
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		get_arg(&data, argv, argc);
		check_philo(&data, argc);
		init_mutex(&data);
		attr_philo(&data);
	}
	else
		printf("Invalid number of arguments\n");
	return (0);
}
