/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:03:09 by divalent          #+#    #+#             */
/*   Updated: 2024/11/19 18:12:46 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eat(t_philo *philo)
{
	if (philo->id % 2 != 0)
		usleep(100);
	if (eat_left(philo) == 1)
		return (1);
	if (philo->amm == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	if (eat_right(philo) == 1)
		return (1);
	return (0);
}

void	eating(t_philo *philo)
{
	long	current_time;

	if (eat(philo) == 1)
		return ;
	pthread_mutex_lock(&philo->data->life);
	if (philo->data->dead == true)
	{
		pthread_mutex_unlock(&philo->data->life);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_unlock(&philo->data->life);
	pthread_mutex_lock(&philo->data->print_mutex);
	current_time = get_time_ms();
	current_time = current_time - philo->data->start_time;
	ft_printf("%d %d is eating\n", current_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	pthread_mutex_lock(&philo->meal);
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(&philo->meal);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->times_eaten += 1;
}

void	sleeping(t_philo *philo)
{
	long	current_time;

	pthread_mutex_lock(&philo->data->life);
	if (philo->data->dead == true)
	{
		pthread_mutex_unlock(&philo->data->life);
		return ;
	}
	pthread_mutex_unlock(&philo->data->life);
	pthread_mutex_lock(&philo->data->print_mutex);
	current_time = get_time_ms();
	current_time = current_time - philo->data->start_time;
	ft_printf("%d %d is sleeping\n", current_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	usleep(philo->data->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	long	current_time;

	pthread_mutex_lock(&philo->data->life);
	if (philo->data->dead == true)
	{
		pthread_mutex_unlock(&philo->data->life);
		return ;
	}
	pthread_mutex_unlock(&philo->data->life);
	pthread_mutex_lock(&philo->data->print_mutex);
	current_time = get_time_ms();
	current_time = current_time - philo->data->start_time;
	ft_printf("%d %d is thinking\n", current_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	usleep(philo->data->time_to_think * 1000);
}

void	*call_actions(void	*arg)
{
	t_philo			*philo;

	philo = (t_philo *) arg;
	pthread_mutex_lock(&philo->data->all_ready);
	pthread_mutex_unlock(&philo->data->all_ready);
	while (1)
	{
		if (philo->times_eaten == philo->data->must_eat)
		{
			pthread_mutex_lock(&philo->data->ff);
			philo->finish = true;
			pthread_mutex_unlock(&philo->data->ff);
			return (0);
		}
		pthread_mutex_lock(&philo->data->life);
		if (philo->data->dead == true)
			return (close_life(philo));
		pthread_mutex_unlock(&philo->data->life);
		eating(philo);
		if (philo->amm == 1)
			return (0);
		sleeping(philo);
		thinking(philo);
	}
	return (0);
}
