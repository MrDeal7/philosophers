/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:03:23 by divalent          #+#    #+#             */
/*   Updated: 2024/11/19 18:08:45 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	time_think(t_data *data)
{
	if (data->num_philos % 2 == 0)
	{
		if (data->time_to_sleep < data->time_to_eat)
			data->time_to_think = data->time_to_eat - data->time_to_sleep;
		else
			data->time_to_think = 0;
	}
	else
		data->time_to_think = (data->time_to_eat * 2) - data->time_to_sleep;
}

void	free_everything(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		free(philo[i]);
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&philo[i]->meal);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->ff);
	pthread_mutex_destroy(&data->life);
	free(philo);
}

void	*close_life(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->life);
	return (0);
}

void	init_last_meal(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		philo[i]->last_meal = data->start_time;
		i++;
	}
}
