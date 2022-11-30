/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:46:05 by fesper-s          #+#    #+#             */
/*   Updated: 2022/11/30 09:00:37 by fesper-s         ###   ########.fr       */
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
