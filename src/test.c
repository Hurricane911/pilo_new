#include "philo.h"

// Add this function prototype at the top with other prototypes
void print_philo_data(t_data *data);

// Add this implementation at the bottom of the file
void print_philo_data(t_data *data)
{
    printf("\n=== Philosophers Configuration ===\n");
    printf("Number of philosophers: %d\n", data->nb_philos);
    printf("Time to die: %d ms\n", data->time_to_die);
    printf("Time to eat: %d ms\n", data->time_to_eat);
    printf("Time to sleep: %d ms\n", data->time_to_sleep);
    printf("Number of meals: %d\n", data->meals_iter);
    
    printf("\n=== Philosophers Status ===\n");
    for (int i = 0; i < data->nb_philos; i++)
    {
        printf("\nPhilosopher %d:\n", data->philo[i].id);
        printf("  Left fork (fork[0]): %d\n", data->philo[i].fork[0]);
        printf("  Right fork (fork[1]): %d\n", data->philo[i].fork[1]);
        printf("  Meals required: %d\n", data->philo[i].meals_required);
        printf("  Last meal time: %ld\n", data->philo[i].last_meal);
    }
    printf("\n===============================\n");
}