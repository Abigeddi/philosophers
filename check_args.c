/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:17:56 by abigeddi          #+#    #+#             */
/*   Updated: 2022/06/06 15:07:18 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_args(t_data *data, int ac, char **av)
{
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	if (ac == 6)
		data->n_eat = ft_atoi(av[5]);
	else
		data->n_eat = -1;
	data->t_sleep = ft_atoi(av[4]);
}

int	init_philo(t_data *data)
{
	int	i;
	
	i = 0;
	data->philos = malloc(sizeof (t_philo) * (data->n_philo));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->philos || !data->forks)
		return(printf ("Error : malloc"),-1);
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (printf("Error mutex init\n"), -1);
		data->philos[i].index = i + 1;
		data->philos[i].number_eaten = 0;
		data->philos[i].last_eat = data->time;
		data->philos[i].data = data;
		data->philos[i].full_eat = 0;
		i++;
	}
	return (1);
}