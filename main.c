/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:06:43 by abigeddi          #+#    #+#             */
/*   Updated: 2022/08/18 19:53:34 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long long time)
{
	long long	t;

	t = get_clock();
	while (get_clock() - t <= time)
	{
		usleep(100);
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (check_param(ac, av) == -1)
		return (1);
	get_param(&info, ac, av);
	if (ft_initier(&info) == -1)
		return (1);
	ft_init_philo(&info);
	manager(&info);
	ft_free(&info);
	return (0);
}
