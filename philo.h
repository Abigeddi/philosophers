/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:07:00 by abigeddi          #+#    #+#             */
/*   Updated: 2022/06/06 14:58:35 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		th;
	long long 		last_eat;
	int				index;
	int				number_eaten;
	int				full_eat;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int					die;
	long long			time;
	int					n_philo;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					n_eat;
	pthread_mutex_t		mutex;
	pthread_mutex_t		mtx_die;
	t_philo				*philos;
	pthread_mutex_t		*forks;
}	t_data;

void	ft_usleep(unsigned long time);
long long	get_time(void);
void	set_forks(t_philo *philo, int lamp);
int	init_philo(t_data *data);
int	ft_atoi ( const  char *str);
#endif