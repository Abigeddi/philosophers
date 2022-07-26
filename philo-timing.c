/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo-timing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:42:29 by abigeddi          #+#    #+#             */
/*   Updated: 2022/07/25 15:36:19 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


long long	get_time(void)
{
	struct timeval	x;

	gettimeofday(&x, NULL);
	return ((x.tv_sec * 1000) + (x.tv_usec / 1000));
}

void	ft_usleep(unsigned long time)
{
	unsigned long	curr;

	curr = get_time();
	while (get_time() - curr < time)
		usleep(50);
}

int	ft_atoi ( const  char *str)
{
	int 	i;
	int 	s;
	int 	r;

	i = 0 ;
	r = 0 ;
	s = 1 ;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13 ))
		i++ ;
	if (str[i] == '-' || str[i] == '+' )
	{
		if (str[i] == '-' )
			s = - 1 ;
		i++ ;
	}
	while (str[i] >= '0' && str[i] <= '9' )
	{
		r = r * 10 + (str[i] - '0' );
		i++ ;
	}
	return (r * s);
}