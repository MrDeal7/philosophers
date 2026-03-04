/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:49:32 by divalent          #+#    #+#             */
/*   Updated: 2024/11/19 18:14:31 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_philos(t_data *data, t_philo **philo)
{
	pthread_t	*threads;
	int			i;

	threads = malloc(sizeof(pthread_t) * (data->num_philos + 1));
	if (!threads)
		return ;
	i = 0;
	pthread_mutex_lock(&data->all_ready);
	while (i < data->num_philos)
	{
		if (pthread_create(&threads[i], NULL,
				call_actions, (void *)philo[i]) != 0)
			break ;
		i++;
	}
	data->start_time = get_time_ms();
	init_last_meal(data, philo);
	pthread_mutex_unlock(&data->all_ready);
	i = 0;
	death_god(data, philo);
	while (i < data->num_philos)
		pthread_join(threads[i++], NULL);
	free(threads);
}

void	assign_forks(t_philo *philo, pthread_mutex_t *forks, int max)
{
	if (philo->id % 2 == 0)
	{
		philo->left_fork = &forks[philo->id - 1];
		philo->right_fork = &forks[philo->id % max];
	}
	else
	{
		philo->right_fork = &forks[philo->id - 1];
		philo->left_fork = &forks[philo->id % max];
	}
}

void	init_philo(t_data *data, t_philo *philo, int i)
{
	philo->id = (i + 1);
	philo->times_eaten = 0;
	philo->left_fork = NULL;
	philo->right_fork = NULL;
	philo->data = data;
	philo->finish = false;
	philo->amm = data->num_philos;
	pthread_mutex_init(&philo->meal, NULL);
}

void	philosophers(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos + 1);
	while (i < data->num_philos)
	{
		philo[i] = malloc(sizeof(t_philo));
		init_philo(data, philo[i], i);
		i++;
	}
	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < data->num_philos)
	{
		assign_forks(philo[i], data->forks, data->num_philos);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_philo		**philo;

	if (argc <= 4 || argc > 6)
		return (write(2, "incorrect amount of args\n", 26), 1);
	prepare_args(&data, argv + 1);
	pthread_mutex_init(&data.print_mutex, NULL);
	pthread_mutex_init(&data.all_ready, NULL);
	pthread_mutex_init(&data.ff, NULL);
	pthread_mutex_init(&data.life, NULL);
	philo = malloc(sizeof(t_philo *) * data.num_philos + 1);
	philosophers(&data, philo);
	create_philos(&data, philo);
	free_everything(&data, philo);
	(void) argv;
	(void) argc;
}
