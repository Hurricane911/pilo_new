/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:52:25 by joyim             #+#    #+#             */
/*   Updated: 2025/02/23 15:34:32 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->data->lock_print);
	
	if (status == GOT_FORK_1)
	{
		printf("pick up fork");
	}

	pthread_mutex_unlock(&philo->data->lock_print);
}