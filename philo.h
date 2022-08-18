/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:07:00 by abigeddi          #+#    #+#             */
/*   Updated: 2022/08/18 19:55:42 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		th;
	long long		last_eat;
	int				index;
	int				n_eat;
	int				full_eat;
	struct s_info	*info;
}					t_philo;

typedef struct s_info
{
	long long			time;
	int					n_philosophers;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					n_must_eat;
	pthread_mutex_t		mutex;
	t_philo				*philos;
	pthread_mutex_t		*forks;
}						t_info;

int			ft_atoi(const char *str);
int			check_param(int ac, char **av);
void		get_param(t_info *info, int ac, char **av);
void		create_philo(t_info *info);
long long	get_clock(void);
int			ft_initier(t_info *info);
int			ft_init_philo(t_info *info);
void		print_philo_task(t_philo *philo, char *s, int boool);
void		*manager(t_info *info);
int			ft_free(t_info *info);
int			ft_isdigit(int c);
void		ft_usleep(long long time);

#endif