/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:07:08 by abigeddi          #+#    #+#             */
/*   Updated: 2022/08/18 19:54:16 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_task(t_philo *philo, char *s, int boool)
{
	pthread_mutex_lock(&philo->info->mutex);
	if (s)
		printf("%lld philo %d %s\n", (get_clock() - philo->info->time) \
			, philo->index, s);
	if (boool)
		pthread_mutex_unlock(&philo->info->mutex);
}

void	lock_forks(t_philo *philo, int boool)
{
	if (boool)
	{
		pthread_mutex_lock(&philo->info->forks[(philo->index - 1) \
			% philo->info->n_philosophers]);
		print_philo_task(philo, "taken a fork", 1);
		pthread_mutex_lock(&philo->info->forks[(philo->index) \
			% philo->info->n_philosophers]);
		print_philo_task(philo, "taken a fork", 1);
	}
	else
	{
		pthread_mutex_unlock(&philo->info->forks[(philo->index - 1) \
			% philo->info->n_philosophers]);
		pthread_mutex_unlock(&philo->info->forks[(philo->index) \
			% philo->info->n_philosophers]);
	}
}

void	*routine(void *av)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = av;
	if (!(philo->index & 1))
		usleep(100);
	philo->last_eat = get_clock();
	while (999)
	{
		lock_forks(philo, 1);
		print_philo_task(philo, "is eating", 1);
		philo->last_eat = get_clock();
		ft_usleep(philo->info->t_eat);
		lock_forks(philo, 0);
		philo->n_eat += 1;
		if (philo->n_eat == philo->info->n_must_eat)
			return (philo->full_eat = 1, NULL);
		print_philo_task(philo, "is sleeping", 1);
		ft_usleep(philo->info->t_sleep);
		print_philo_task(philo, "is thinking", 1);
	}
	return (0);
}

int	ft_init_philo(t_info *info)
{
	int	i;

	i = -1;
	pthread_mutex_init(&info->mutex, NULL);
	while (++i < info->n_philosophers)
		pthread_mutex_init(&info->forks[i], NULL);
	i = -1;
	while (++i < info->n_philosophers)
		pthread_create(&info->philos[i].th, NULL, routine, &info->philos[i]);
	i = -1;
	while (++i < info->n_philosophers)
		pthread_detach(info->philos[i].th);
	return (1);
}

int	ft_initier(t_info *info)
{
	int	i;

	i = 0;
	info->philos = malloc(sizeof (t_philo) * info->n_philosophers);
	info->forks = malloc(sizeof (pthread_mutex_t) * info->n_philosophers);
	info->time = get_clock();
	if (!info->philos || !info->forks)
		return (printf("malloc error !\n"), -1);
	while (i < info->n_philosophers)
	{
		info->philos[i].index = i + 1;
		info->philos[i].n_eat = 0;
		info->philos[i].last_eat = -1;
		info->philos[i].full_eat = 0;
		info->philos[i].info = info;
		i++;
	}
	return (1);
}
