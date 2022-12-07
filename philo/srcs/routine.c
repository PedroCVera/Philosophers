/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:15:27 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/12/07 18:55:08 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo_stuff(void *cenas)
{
	t_philo *p;

	p = (t_philo *)cenas;
	while (checker_deader(p) == 0)
	{
		printf("ananas%d\n", p->nbr);
		yeeat(p);
		printf("mango\n");
		if (p->data->philo_eat != -3 && p->times_eat == p->data->philo_eat)
			break ;
		if (checker_deader(p) == 0)
			philo_print(p, "is sleeping");
		xonar(p, p->data->tt_s);
		break ;
	}
	return (NULL);
}
