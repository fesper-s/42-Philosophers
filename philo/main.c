/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:16:42 by fesper-s          #+#    #+#             */
/*   Updated: 2022/11/18 16:42:51 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_arg(t_philo *stats, char **str, int size)
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
	stats->nbphilo = ft_atoi(str[1]);
	stats->ttdie = ft_atoi(str[2]);
	stats->tteat = ft_atoi(str[3]);
	stats->ttsleep = ft_atoi(str[4]);
	if (size == 6)
		stats->nbmeals = ft_atoi(str[5]);
}

void	check_philo(t_philo *stats, int size)
{
	printf("Number of Philosophers: %d\n", stats->nbphilo);
	printf("Time do die: %d\n", stats->ttdie);
	printf("Time to eat: %d\n", stats->tteat);
	printf("Time to sleep: %d\n", stats->ttsleep);
	if (size == 6)
		printf("Number of meals: %d\n", stats->nbmeals);
}

int	main(int argc, char **argv)
{
	t_philo	stats;

	if (argc == 5 || argc == 6)
	{
		get_arg(&stats, argv, argc);
		check_philo(&stats, argc);
	}
	else
		printf("Invalid number of arguments\n");
	return (0);
}
