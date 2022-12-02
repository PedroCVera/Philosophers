/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:46:15 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/12/02 17:15:11 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	mutex_init(t_philo **p, int philo_nbr)
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

int	create_forks(t_forks **forks, int philo_nbr)
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

int	philo_allocation(t_forks **f, t_info *d, t_philo **p, int *ded)
{
	int	i;

	i = -1;
	(*p) = malloc(sizeof(t_philo) * d->philo_eat);
	if (!(*p))
		return (NULL);
	while(++i < d->philo_nbr)
	{
		(*p)[i].dead = ded;
		(*p)[i].nbr = i + 1;
		(*p)[i].R = (*f)[i];
		(*p)[i].times_eat = 0;
		if (i == 0)
			(*p)[i].L = (*f)[d->philo_nbr - 1];
		else
			(*p)[i].L = (*f)[i - 1];
		(*p)[i].data = d;
	}
	return (0);
}

int	philo_init(t_forks **f, t_info *i, t_philo **p, int *dead)
{
	int	ind;

	ind = -1;
	if (!philo_allocation(f, i, p, dead) || !init_mutex(p, i->philo_nbr))
		return (1);
		i = -1;
	i->st = time_ms();
	while (++i < i->philo_nbr)
	{
		if (pthread_create(&((*p)[ind].id), NULL, philo_routine, \
		(void *)(&((*p)[ind]))))
		{
			printf("Error creating thread\n");
			return (1);
		}
	}
	return (0);
}