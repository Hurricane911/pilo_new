/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:50:26 by joyim             #+#    #+#             */
/*   Updated: 2025/02/23 14:07:58 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void init(t_data *data, int ac, char **av);
void init_locks(t_data *data);
void init_philo(t_data *data);

void init(t_data *data, int ac, char **av)
{
	data->timer = 0;
	data->nb_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->meals_iter = -1;
	if(ac == 6)
		data->meals_iter = ft_atoi(av[5]);
	data->is_exit = 0;
	data->dead_philo = 0;
	init_locks(data);
	init_philo(data);
}

void init_locks(t_data *data)
{
	int i;

	i = -1;
	while(++i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->lock_forks[i], 0) != 0)
			return (handle_error(data, MUTEX_ERROR));
	}
	if (pthread_mutex_init(&data->lock_is_exit, 0) != 0 \
	|| pthread_mutex_init(&data->lock_print, 0) != 0 \
	|| pthread_mutex_init(&data->lock_global, 0) != 0 \
	|| pthread_mutex_init(&data->lock_is_dead, 0) != 0)
		return (handle_error(data, MUTEX_ERROR));
}

void init_philo(t_data *data)
{
	int i;

	i = -1;
	while(++i < data->nb_philos)
	{
		data->philo[i].id = i + 1;
		data->philo[i].meals_required = data->meals_needed;
		assign_forks(&data->philo[i], data);
		data->philo[i].last_meal = 0;
		if (pthread_mutex_init(&data->philo[i].lock_eat_routine, 0) != 0)
			return (handle_error(data, MUTEX_ERROR));
		data->philo[i].data = data;
	}
}

void assign_forks(t_philo *philo, t_data *data)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id % data->nb_philos) + 1;
}