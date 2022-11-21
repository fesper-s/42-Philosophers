/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:16:42 by fesper-s          #+#    #+#             */
/*   Updated: 2022/11/21 10:40:36 by fesper-s         ###   ########.fr       */
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
	printf("Time do die: %d\n", data->ttdie);
	printf("Time to eat: %d\n", data->tteat);
	printf("Time to sleep: %d\n", data->ttsleep);
	if (size == 6)
		printf("Number of meals: %d\n", data->nbmeals);
}

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	printf("ESTA PORRA %d\n", philo->id);
	return (NULL);
}

void	attr_philo(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * data->nbphilo);
	i = -1;
	while (++i < data->nbphilo)
	{
		data->philo[i].id = i;
		data->philo[i].fork_l = i;
		data->philo[i].fork_r = (i + 1) % data->nbphilo;
	}
	i = -1;
	while (1)
	{
		while (++i < data->nbphilo)
		{
			pthread_create(&data->philo[i].threads, NULL, &routine, \
				&data->philo[i]);
		}
		i = -1;
		while (++i < data->nbphilo)
		{
			pthread_join(data->philo[i].threads, NULL);
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		get_arg(&data, argv, argc);
		check_philo(&data, argc);
		attr_philo(&data);
	}
	else
		printf("Invalid number of arguments\n");
	return (0);
}
