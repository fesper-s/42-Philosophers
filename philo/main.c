/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:16:42 by fesper-s          #+#    #+#             */
/*   Updated: 2022/11/29 10:12:33 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (get_arg(&data, argv, argc) != 0)
			return (1);
		init_mutex(&data);
		attr_philo(&data);
		destroy_mutex(&data);
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
				ft_putstr_fd("Error: parameter is not a number\n", 2);
				return (1);
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
