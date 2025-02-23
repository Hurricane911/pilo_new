/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:07:13 by joyim             #+#    #+#             */
/*   Updated: 2025/02/23 15:29:17 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void execution(t_data *data);

int main(int ac, char **av)
{
	t_data data;
	if (check_input(ac, av) != 0)
	{
		print_instruction();
		return (ARG_ERROR);
	}
	init(&data, ac, av);
	print_philo_data(&data);
	execution(&data);
	exit_execution(&data);
	return (0);
}

void execution(t_data *data)
{
	int	i;

	i = 0;
	if(pthread_create(&data->philo[i].thread, NULL, routine, \
		(void *)&data->philo[i]) == 0)
		printf("hello1");

}

void *routine (void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	if (philo->data->nb_philos == 1)
		return (single_philo(philo));
	
}

void *single_philo(t_philo *philo)
{
	printf("hello2");
	pthread_mutex_lock(&philo->data->lock_forks[philo->fork[0]]);
	print_action(philo, GOT_FORK_1);
}

void exit_execution(t_data *data)
{
	int i;

	i = 0;
	while(i < data->nb_philos)
		pthread_join(data->philo[i++].thread, NULL);
	cleanup(data);
}

