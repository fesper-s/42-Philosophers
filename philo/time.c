/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:46:05 by fesper-s          #+#    #+#             */
/*   Updated: 2022/12/01 13:36:53 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	start_count(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		ft_putstr_fd("Fail to get time of day\n", 2);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	check_health(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (data->philos_ate == data->nbphilo)
			break ;
		if (start_count() - philo[i].last_meal > (unsigned long) data->ttdie)
		{
			data->died = 1;
			printf("%lu %d died\n", start_count() - \
				data->time, philo[i].id);
			break ;
		}
		i = (i + 1) % data->nbphilo;
	}
}
