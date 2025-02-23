/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:08:06 by joyim             #+#    #+#             */
/*   Updated: 2025/02/23 12:23:59 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>

# define ARG_ERROR -1
# define FORMAT_ERROR -2
# define MALLOC_ERROR -3
# define MUTEX_ERROR -4
# define THREAD_ERROR -5
# define MAX_PHILO 200

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

# define ERR_MSG_ARG "Arg Error: ./philo\n\
1 - <total_philos>\n\
2 - <time_to_die>\n\
3 - <time_to_eat>\n\
4 - <time_to_sleep>\n\
5 - <meals_needed>"

# define ERR_MSG_FORMAT "Format Error:\n\
1 - detected non-integer\n\
2 - philo exceed 200\n\
3 - detected negative values"
# define ERR_MSG_MALLOC "Malloc Error"
# define ERR_MSG_MUTEX "Mutex Error"
# define ERR_MSG_THREAD "Thread Error"

typedef enum e_status
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5,
}	t_status;

typedef struct s_philo{
	pthread_t	thread;
	struct s_data *data;
	int	id;
	int meals_required;
	int fork[2];
	time_t last_meal;
	pthread_mutex_t	lock_eat_routine;
}t_philo;

typedef struct s_data{

	time_t			timer;
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_needed;
	int				meals_iter;
	int				is_exit;
	int				dead_philo;
	pthread_t		monitor;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	lock_is_exit;
	pthread_mutex_t	lock_is_dead;
	pthread_mutex_t	lock_global;
	pthread_mutex_t	lock_forks[MAX_PHILO];
	t_philo			philo[MAX_PHILO];

}t_data;

// main.c
void execution(t_data *data);
void exit_execution(t_data *data);


// init.c
void init(t_data *data, int ac, char **av);
void init_locks(t_data *data);
void init_philo(t_data *data);

// parsing
int check_input(int ac, char **av);
void print_instruction(void);

// error.c
void	handle_error(t_data *data, int error_num);
void	cleanup(t_data *data);
void	destroy_mutexes(t_data *data);

// routine.c
void *routine(void *data);
// void single_philo_function();


// libft_utils
int	ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);

// test
void print_philo_data(t_data *data);

#endif