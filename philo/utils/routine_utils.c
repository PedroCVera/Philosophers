/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:37:33 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/12/05 17:49:43 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	checker_deader(t_philo *p)
{
	pthread_mutex_lock(p->d_check);
	if (p->dead == 1)
	{
		pthread_mutex_unlock(p->d_check);
		return (1);
	}
	if ((time_now(p) - p->last_eat) >= p->data->tt_d)
	{
		p->dead = 1;
		pthread_mutex_unlock(p->d_check);
		return (1);
	}
	pthread_mutex_unlock(p->d_check);
	return (0);
}

int	xonar(t_philo *philo)
{
	
}