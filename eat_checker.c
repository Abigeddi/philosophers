/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:42:29 by abigeddi          #+#    #+#             */
/*   Updated: 2022/08/18 19:53:58 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->n_philosophers)
		pthread_mutex_destroy(&(info->forks[i]));
	pthread_mutex_destroy(&(info->mutex));
	free(info->philos);
	free(info->forks);
	return (0);
}

static int	check_n_eat(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philosophers)
	{
		if (info->philos[i].full_eat == 0)
			return (0);
		i++;
	}
	return (1);
}

void	*manager(t_info *info)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == info->n_philosophers)
			i = 0;
		if (info->n_must_eat != -1)
		{
			if (check_n_eat(info))
				return (NULL);
		}
		if ((get_clock() - info->philos[i].last_eat) >= info->t_die \
			&& info->philos[i].last_eat != -1)
		{
			print_philo_task(&info->philos[i], "died", 0);
			return (NULL);
		}
		i++;
	}
	return (NULL);
}
