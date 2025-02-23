/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:37:48 by joyim             #+#    #+#             */
/*   Updated: 2025/02/20 10:58:28 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_error(t_data *data, int error_num);
void	cleanup(t_data *data);
void	destroy_mutexes(t_data *data);

void	handle_error(t_data *data, int error_num)
{
	if (error_num == ARG_ERROR)
	ft_putendl_fd(ERR_MSG_ARG, STDERR_FILENO);
	if (error_num == FORMAT_ERROR)
	ft_putendl_fd(ERR_MSG_FORMAT, STDERR_FILENO);
	if (error_num == MALLOC_ERROR)
	ft_putendl_fd(ERR_MSG_MALLOC, STDERR_FILENO);
	if (error_num == MUTEX_ERROR)
	ft_putendl_fd(ERR_MSG_MUTEX, STDERR_FILENO);
	if (data)
		cleanup(data);
	exit(EXIT_FAILURE);
}

void cleanup (t_data *data)
{
	if (data->nb_philos)
		destroy_mutexes(data);
}

void destroy_mutexes(t_data *data)
{
	int i;

	i = -1;
	while(++i < data->nb_philos)
	{
		pthread_mutex_destroy(&data->lock_forks[i]);
		pthread_mutex_destroy(&data->philo[i].lock_eat_routine);
	}
	pthread_mutex_destroy(&data->lock_is_exit);
	pthread_mutex_destroy(&data->lock_print);
	pthread_mutex_destroy(&data->lock_is_dead);
}

