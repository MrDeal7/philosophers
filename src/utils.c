/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:49:25 by divalent          #+#    #+#             */
/*   Updated: 2024/11/19 18:14:41 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eat_left(t_philo *philo)
{
	long	current_time;

	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->data->life);
	if (philo->data->dead == true)
	{
		pthread_mutex_unlock(&philo->data->life);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->life);
	pthread_mutex_lock(&philo->data->print_mutex);
	current_time = get_time_ms();
	current_time = current_time - philo->data->start_time;
	ft_printf("%d %d has taken a fork\n", current_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	return (0);
}

int	eat_right(t_philo *philo)
{
	long	current_time;

	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->data->life);
	if (philo->data->dead == true)
	{
		pthread_mutex_unlock(&philo->data->life);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->life);
	pthread_mutex_lock(&philo->data->print_mutex);
	current_time = get_time_ms();
	current_time = current_time - philo->data->start_time;
	ft_printf("%d %d has taken a fork\n", current_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	return (0);
}

int	all_finished(t_data *data, t_philo **philo)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	pthread_mutex_lock(&data->ff);
	while (philo[i])
	{
		if (philo[i]->finish == false)
			flag = 0;
		i++;
	}
	pthread_mutex_unlock(&data->ff);
	return (flag);
}

void	death_god_lackey(t_data *data, int i)
{
	long	current_time;

	pthread_mutex_lock(&data->print_mutex);
	data->dead_id = i + 1;
	current_time = get_time_ms();
	current_time = current_time - data->start_time;
	pthread_mutex_lock(&data->life);
	if (data->dead == true)
		ft_printf("%d %d died\n", current_time, data->dead_id);
	pthread_mutex_unlock(&data->life);
	pthread_mutex_unlock(&data->print_mutex);
}

void	death_god(t_data *data, t_philo **philo)
{
	long	time_since_last_meal;
	int		i;

	i = 0;
	while (1)
	{
		if (all_finished(data, philo) == 1)
			break ;
		pthread_mutex_lock(&philo[i]->meal);
		time_since_last_meal = get_time_ms() - philo[i]->last_meal;
		pthread_mutex_unlock(&philo[i]->meal);
		if (time_since_last_meal >= data->time_to_die
			&& philo[i]->finish == false)
		{
			pthread_mutex_lock(&data->life);
			data->dead = true;
			pthread_mutex_unlock(&data->life);
			break ;
		}
		if (++i == data->num_philos)
			i = 0;
		usleep(50);
	}
	death_god_lackey(data, i);
}
