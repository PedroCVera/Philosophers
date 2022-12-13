/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:46:15 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/12/13 18:02:43 by pcoimbra         ###   ########.fr       */
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
		return (error_mutexes(print, dead));
	i = 0;
	while (i < philo_nbr)
	{
		(*p)[i].print = print;
		(*p)[i].d_check = dead;
		i++;
	}
	return (0);
}

int	create_forks(t_forks **forks, int n_phil)
{
	int				i;
	int				*f;
	pthread_mutex_t	*check;

	f = malloc(sizeof(int) * n_phil);
	if (!f)
		return (1);
	i = -1;
	while (++i < n_phil)
		f[i] = 0;
	i = -1;
	(*forks) = malloc(sizeof(t_forks) * n_phil);
	(check) = malloc(sizeof(pthread_mutex_t) * n_phil);
	if (!(*forks) || !check)
		return (error_forks(*forks, check));
	while (++i < n_phil)
	{
		(*forks)[i].fork = &(f[i]);
		pthread_mutex_init(&((check)[i]), NULL);
		(*forks)[i].check = &(check[i]);
	}
	return (0);
}

int	philo_allocation(t_forks **f, t_info *d, t_philo **p, int *ded)
{
	int	ind;

	(*p) = malloc(sizeof(t_philo) * d->philo_nbr);
	if (!(*p))
		return (1);
	ind = -1;
	while (++ind < d->philo_nbr)
	{
		(*p)[ind].dead = ded;
		(*p)[ind].nbr = ind + 1;
		(*p)[ind].r = (*f)[ind];
		(*p)[ind].times_eat = 0;
		if (ind == 0)
			(*p)[ind].l = (*f)[d->philo_nbr - 1];
		else
			(*p)[ind].l = (*f)[ind - 1];
		(*p)[ind].data = d;
	}
	return (0);
}

int	philo_init(t_forks **f, t_info *i, t_philo **p, int *dead)
{
	int	ind;

	if (philo_allocation(f, i, p, dead) || mutex_init(p, i->philo_nbr))
		return (1);
	ind = -1;
	i->st = time_philo();
	while (++ind < i->philo_nbr)
	{
		if (pthread_create(&((*p)[ind].id), NULL, philo_stuff, \
		(void *)(&((*p)[ind]))))
		{
			printf("Error creating thread\n");
			return (1);
		}
	}
	return (0);
}
