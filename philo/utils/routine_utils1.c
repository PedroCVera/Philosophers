/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:33:41 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/12/07 15:43:01 by pcoimbra         ###   ########.fr       */
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