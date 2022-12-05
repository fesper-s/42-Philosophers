/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:57:37 by fesper-s          #+#    #+#             */
/*   Updated: 2022/12/05 16:26:12 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbphilo);
	i = -1;
	while (++i < data->nbphilo)
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
			ft_putstr_fd("Error: Failed to init mutex\n", 2);
	if (pthread_mutex_init(&(data->writing), NULL) != 0)
		ft_putstr_fd("Error: Failed to init mutex\n", 2);
}

void	dstr_mutex_free_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbphilo)
		if (pthread_mutex_destroy(&(data->forks[i])) != 0)
			ft_putstr_fd("Error: Failed to destroy mutex\n", 2);
	if (pthread_mutex_destroy(&(data->writing)) != 0)
		ft_putstr_fd("Error: Failed to destroy mutex\n", 2);
	free(data->philo);
	free(data->forks);
}

void	print_msg(char *str, t_data *data, int id)
{
	if (pthread_mutex_lock(&(data->writing)) != 0)
		ft_putstr_fd("Error: Failed to lock mutex\n", 2);
	if (!data->died)
		printf("%lu %d %s\n", start_count() - data->time, id, str);
	if (pthread_mutex_unlock(&(data->writing)) != 0)
		ft_putstr_fd("Error: Failed to unlock mutex\n", 2);
}

void	eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (pthread_mutex_lock(&(data->forks[philo->fork_l])) == 0)
		print_msg("has taken a fork", data, philo->id);
	else
		ft_putstr_fd("Error: Fail to lock mutex\n", 2);
	if (pthread_mutex_lock(&(data->forks[philo->fork_r])) == 0)
		print_msg("has taken a fork", data, philo->id);
	else
		ft_putstr_fd("Error: Fail to lock mutex\n", 2);
	print_msg("is eating", data, philo->id);
	usleep(data->tteat * 1000);
	philo->last_meal = start_count();
	philo->meals++;
	if (philo->meals == data->nbmeals)
		data->philos_ate++;
	if (pthread_mutex_unlock(&data->forks[philo->fork_l]) != 0)
		ft_putstr_fd("Error: Fail to unlock mutex\n", 2);
	if (pthread_mutex_unlock(&data->forks[philo->fork_r]) != 0)
		ft_putstr_fd("Error: Fail to unlock mutex\n", 2);
	print_msg("is sleeping", data, philo->id);
	usleep(data->ttsleep * 1000);
	print_msg("is thinking", data, philo->id);
}
