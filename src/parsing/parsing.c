/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:13:18 by joyim             #+#    #+#             */
/*   Updated: 2025/02/20 11:04:55 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_instruction(void)
{
	printf("\t\tWRONG INPUT!\n\n");
	printf("./philo nb_philos time_to_die ");
	printf("time_to_eat time_to_sleep ");
	printf("number_of_times_each_philosopher_must_eat ");
	printf("(optional argument)\n");
	printf("Example:\n\n");
	printf("./philo 4 800 200 200 5\n\n");
	printf("nb_philos: 1-200\n");
	printf("time_to_die: 60+\n");
	printf("time_to_eat: 60+\n");
	printf("time_to_sleep: 60+\n");
	printf("number_of_times_each_philosopher_must_eat: ");
	printf("0+\n");
}

int ARG_ERROR_check(int ac, char **av)
{
	int i;

	i = 1;
	if (ac == 6 && atoi(av[5]) <= 0)
		return (ARG_ERROR);
	if (atoi(av[i]) < 1 || atoi(av[i]) > 200)
		return (ARG_ERROR);
	while (++i < 5)
	{
		if (atoi(av[i]) < 60)
			return(ARG_ERROR);
	}
	return (0);
}

int is_input_digit(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while(i < ac)
	{
		j = 0;
		while(av[i][j] != '\0')
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (ARG_ERROR);
			j++;
		}
		i++;
	}
	return (0);
}

int check_input(int ac, char **av)
{
    if (ac < 5 || ac > 6)
        return (ARG_ERROR);
    if (is_input_digit(ac, av) != 0)
        return (ARG_ERROR);
    if (ARG_ERROR_check(ac, av))
        return (ARG_ERROR);
    return (0);
}