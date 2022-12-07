/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:37:33 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/12/07 19:08:29 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	fork_taker(t_philo *p)
{
	while (checker_deader(p) == 0)
	{
		pthread_mutex_lock(p->R.check);
		if (p->R.fork == 0)
		{
			p->R.fork = 1;
			pthread_mutex_unlock(p->R.check);
			break ;
		}
		pthread_mutex_unlock(p->R.check);
	}
	if (checker_deader(p) == 0)
		philo_print(p, "has taken a fork\n");
	while (checker_deader(p) == 0)
	{
		pthread_mutex_lock(p->L.check);
		if (p->L.fork == 0)
		{
			p->L.fork = 1;
			pthread_mutex_unlock(p->L.check);
			break ;
		}
		pthread_mutex_unlock(p->L.check);
	}
}

void	drop_forks(t_philo *p)
{
	pthread_mutex_lock(p->L.check);
	p->L.fork = 0;
	pthread_mutex_unlock(p->L.check);
	pthread_mutex_lock(p->R.check);
	p->R.fork = 0;
	pthread_mutex_unlock(p->R.check);
}

int	yeeat(t_philo *p)
{
	fork_taker(p);
	if (checker_deader(p) == 0)
		print_eat(p);
	p->times_eat++;
	p->last_eat = time_now(p);
	if (xonar(p, p->data->tt_e) == 1)
		return (1);
	drop_forks(p);
	return (0);
}

int	checker_deader(t_philo *p)
{
	pthread_mutex_lock(p->d_check);
	if (*(p->dead) == 1)
	{
		pthread_mutex_unlock(p->d_check);
		return (1);
	}
	printf("adeus:%d\n", p->nbr);
	if ((time_now(p) - p->last_eat) >= p->data->tt_d)
	{
		*(p->dead) = 1;
		printf("eu nao devia estar aqui\n");
		pthread_mutex_unlock(p->d_check);
		return (1);
	}
	printf("geronimo:%d\n", p->nbr);
	pthread_mutex_unlock(p->d_check);
	return (0);
}

int	xonar(t_philo *philo, unsigned long time)
{
	unsigned long	timepassed;
	unsigned long	start;

	start = time_now(philo);
	timepassed = 0;
	while (timepassed <= time && !checker_deader(philo))
	{
		if (!checker_deader(philo))
		{
			usleep(100);
			timepassed = time_now(philo) - start;
		}
		else
			return (1);
	}
	if (timepassed >= time)
		return (0);
	return (1);
}