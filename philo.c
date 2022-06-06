/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:07:08 by abigeddi          #+#    #+#             */
/*   Updated: 2022/06/06 15:13:03 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_status(t_philo *philo, char *s, int lamp)
{
	pthread_mutex_lock(&philo->data->mutex);
	if (s)
		printf("%lld philo %d %s\n",(get_time() - philo->data->time), philo->index, s);
	if (lamp)
		pthread_mutex_unlock(&philo->data->mutex);
}

void	set_forks(t_philo *philo, int lamp)
{
	if (lamp)
	{
		pthread_mutex_lock(&philo->data->forks[philo->index - 1] % philo->data->n_philo);
		philo_status()
	}
}

void	*routine(void *av)
{
	t_philo	*philo;

	philo = av;
	if (!(philo->index & 1))
		ft_usleep(philo->data->t_eat / 2);
	while (1)
	{
		sets_fork(philo, 1);
		philo_status(philo, "is eating", 1);
		ft_usleep(philo->data->t_eat);
		sets_fork(philo, 0);
		philo->last_eat = get_time();
		philo_status(philo, "is sleeping", 1);
		ft_usleep(philo->data->t_sleep);
		philo_status(philo, "is thinking", 1);
		philo->number_eaten += 1;
		if (philo->number_eaten >= philo->data->n_eat)
			philo->full_eat = 1;
	}
}

void	init_philo(t_data *data)
{
	int	i;
	
	i = 0;
	pthread_mutex_init(&data->mutex, NULL);
	while (i < data->n_philo)
	{
		pthread_create(&data->philos[i].th,NULL,routine,&data->philos[i].th);
		i++;
	}
}