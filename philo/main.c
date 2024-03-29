/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:16:42 by fesper-s          #+#    #+#             */
/*   Updated: 2022/12/12 10:24:12 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		init_vars(&data);
		if (get_arg(&data, argv, argc) != 0)
			return (1);
		init_mutex(&data);
		attr_philo(&data);
		dstr_mutex_free_data(&data);
	}
	else
		printf("Invalid number of arguments\n");
	return (0);
}

int	get_arg(t_data *data, char **str, int size)
{
	int	i;
	int	j;

	i = 0;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (!ft_isdigit(str[i][j]))
			{
				ft_putstr_fd("Error: Invalid parameter\n", 2);
				return (-1);
			}
		}
	}
	data->nbphilo = ft_atoi(str[1]);
	data->ttdie = ft_atoi(str[2]);
	data->tteat = ft_atoi(str[3]);
	data->ttsleep = ft_atoi(str[4]);
	if (size == 6)
		data->nbmeals = ft_atoi(str[5]);
	return (0);
}

void	init_vars(t_data *data)
{
	data->nbphilo = 0;
	data->ttdie = 0;
	data->tteat = 0;
	data->ttsleep = 0;
	data->nbmeals = 0;
	data->died = 0;
	data->philos_ate = 0;
}
