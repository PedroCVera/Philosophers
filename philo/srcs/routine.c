/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:15:27 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/12/05 17:49:27 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo_stuff(void *cenas)
{
	t_philo *philo;

	philo = (t_philo *)cenas;
	while (checker_deader(philo) == 0)
	{
		xonar(philo);
		wife_beater();
	}
}