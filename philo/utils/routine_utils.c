/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:37:33 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/12/13 16:42:19 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	fork_taker(t_philo *p)
{
	while (checker_deader(p) == 0)
	{
		pthread_mutex_lock(p->R.check);
		if (*(p->R.fork) == 0)
		{
			*(p->R.fork) = 1;
			pthread_mutex_unlock(p->R.check);
			break ;
		}
		pthread_mutex_unlock(p->R.check);
	}
	if (check_dead(p) == 0)
		philo_print(p, "has taken a fork");
	while (checker_deader(p) == 0)
	{
		pthread_mutex_lock(p->L.check);
		if (*(p->L.fork) == 0)
		{
			*(p->L.fork) = 1;
			pthread_mutex_unlock(p->L.check);
			break ;
		}
		pthread_mutex_unlock(p->L.check);
	}
}

void	drop_forks(t_philo *p)
{
	pthread_mutex_lock(p->L.check);
	*(p->L.fork) = 0;
	pthread_mutex_unlock(p->L.check);
	pthread_mutex_lock(p->R.check);
	*(p->R.fork) = 0;
	pthread_mutex_unlock(p->R.check);
}

int	yeeat(t_philo *p)
{
	fork_taker(p);
	if (check_dead(p) == 0)
		print_eat(p);
	p->times_eat++;
	p->last_eat = time_now(p);
	if (xonar(p, p->data->tt_e) == 1)
		return (1);
	drop_forks(p);
	return (0);
}

int	xonar(t_philo *p, unsigned long time)
{
	unsigned long	s_start;
	unsigned long	t_passed;

	t_passed = 0;
	s_start = time_now(p);
	while (!checker_deader(p) && !(t_passed >= time))
	{
		if (check_dead(p))
			return (1);
		usleep(100);
		t_passed = time_now(p) - s_start;
	}
	if (t_passed >= time)
		return (0);
	return (1);
}

void	fkysleep(unsigned long time)
{
	unsigned long	timepassed;
	unsigned long	st;

	st = time_philo();
	timepassed = 0;
	while (timepassed < time)
		timepassed = time_philo() - st;
}