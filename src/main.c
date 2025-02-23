/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:07:13 by joyim             #+#    #+#             */
/*   Updated: 2025/02/23 12:25:03 by joyim            ###   ########.fr       */
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
	// execution(&data);
	printf("hello");
	exit_execution(&data);
	return (0);
}



void exit_execution(t_data *data)
{
	int i;

	i = 0;
	while(i < data->nb_philos)
		pthread_join(data->philo[i++].thread, NULL);
	cleanup(data);
}

