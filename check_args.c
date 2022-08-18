/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:17:56 by abigeddi          #+#    #+#             */
/*   Updated: 2022/08/17 18:41:21 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_clock(void)
{
	struct timeval	temp;

	gettimeofday(&temp, NULL);
	return ((temp.tv_sec * 1000) + (temp.tv_usec / 1000));
}

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	r;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r * s);
}

int	check_param(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac != 5 && ac != 6)
		return (printf("syntax error"), -1);
	while (i < ac)
	{
		j = 0;
		if (ft_atoi(av[i]) <= 0)
			return (printf("syntax error\n"), -1);
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (printf("syntax error\n"), -1);
			j++;
		}	
		i++;
	}
	return (1);
}

void	get_param(t_info *info, int ac, char **av)
{
	info->n_philosophers = ft_atoi(av[1]);
	info->t_die = ft_atoi(av[2]);
	info->t_eat = ft_atoi(av[3]);
	info->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->n_must_eat = ft_atoi(av[5]);
	else
		info->n_must_eat = -1;
}
