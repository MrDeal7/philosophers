/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:04:25 by divalent          #+#    #+#             */
/*   Updated: 2024/11/19 17:04:26 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *nptr)
{
	int		n;
	int		sign;
	int		result;

	result = 0;
	sign = 1;
	n = 0;
	while ((nptr[n] == ' ') || (nptr[n] >= 9 && nptr[n] <= 13))
		n++;
	if (nptr[n] == '+' || nptr[n] == '-')
	{
		if (nptr[n] == '-')
			sign = -sign;
		n++;
	}
	while (nptr[n] >= '0' && nptr[n] <= '9')
	{
		result = (result * 10) + (nptr[n] - '0');
		n++;
	}
	return (result * sign);
}

void	prepare_args(t_data *data, char **argv)
{
	data->num_philos = ft_atoi(argv[0]);
	data->time_to_die = ft_atoi(argv[1]);
	data->time_to_eat = ft_atoi(argv[2]);
	data->time_to_sleep = ft_atoi(argv[3]);
	data->dead = false;
	if (argv[4])
		data->must_eat = ft_atoi(argv[4]);
	else
		data->must_eat = -1;
	time_think(data);
}
