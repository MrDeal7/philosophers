/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:04:45 by divalent          #+#    #+#             */
/*   Updated: 2024/11/19 18:09:17 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> 
# include <sys/types.h>
# include <sys/wait.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

# include "ft_printf.h"

typedef struct s_philo
{
	int				id;
	int				times_eaten;
	long			last_meal;
	bool			finish;
	int				amm;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				dead_id;
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				must_eat;
	bool			dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	ff;
	pthread_mutex_t	all_ready;
	pthread_mutex_t	life;
	long			start_time;
}					t_data;

void	ft_putendl_fd(char *s, int fd);
int		eat_left(t_philo *philo);
int		eat_right(t_philo *philo);
void	*call_actions(void	*arg);
void	free_everything(t_data *data, t_philo **philo);
void	prepare_args(t_data *data, char **argv);
void	death_god(t_data *data, t_philo **philo);
long	get_time_ms(void);
void	time_think(t_data *data);
void	*close_life(t_philo *philo);
void	init_last_meal(t_data *data, t_philo **philo);

#endif