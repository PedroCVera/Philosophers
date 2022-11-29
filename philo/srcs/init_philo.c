/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:46:15 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/11/29 17:29:47 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_mutex(t_philo **p, int philo_nbr)
{
	pthread_mutex_t	*print;
	pthread_mutex_t	*dead;
	int				i;
	
	print = (malloc(sizeof(pthread_mutex_t) * philo_nbr));
	dead = (malloc(sizeof(pthread_mutex_t) * philo_nbr));
	if (!dead || !print)
		return (1);
	if (pthread_mutex_init((dead), NULL) || pthread_mutex_init((print), NULL))
		return (1);
	i = 0;
	while (i < philo_nbr)
	{
		(*p)[i].print = print;
		(*p)[i].dead = dead;
		i++;
	}
	return (0);
}

int	creat_forks(t_forks **forks, int philo_nbr)
{
	int				i;
	pthread_mutex_t	*check;

	i = -1;
	(*forks) = malloc(sizeof(t_forks) * philo_nbr);
	(check) = malloc(sizeof(pthread_mutex_t) * philo_nbr);
	if (!forks || !check)
		return (1);
	while (++i < philo_nbr)
	{
		(*forks)[i].fork = 0;
		pthread_mutex_init(&((check)[i]), NULL);
		(*forks)[i].check = &(check[i]);
	}
	return (0);
}