/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:33:41 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/12/09 17:12:13 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_print(t_philo *p, char *str)
{
	pthread_mutex_lock(p->print);
	printf("%lu %d %s\n", time_now(p), p->nbr, str);
	pthread_mutex_unlock(p->print);
}

void	print_eat(t_philo *p)
{
		philo_print(p, "has taken a fork");
		philo_print(p, "is eating");
}

int	checker_deader(t_philo *p)
{
	if (check_dead(p) == 1)
		return (1);
	if ((time_now(p) - p->last_eat) >= p->data->tt_d)
	{
		pthread_mutex_lock(p->d_check);
		p->dead++;
		if (*(p->dead) == 1)
			philo_print(p, "died");
		pthread_mutex_unlock(p->d_check);
		return (1);
	}
	return (0);
}

int	check_dead(t_philo *p)
{
	pthread_mutex_lock(p->d_check);
	if (*(p->dead) == 1)
	{
		pthread_mutex_unlock(p->d_check);
		return (1);
	}
	pthread_mutex_unlock(p->d_check);
	return (0);
}