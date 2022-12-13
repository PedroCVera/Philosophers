/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:04:28 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/12/13 17:09:41 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	end_free(t_philo *p, t_forks *forks, t_info d)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(p->print);
	pthread_mutex_destroy(p->d_check);
	while (++i < d.philo_nbr)
	{
		pthread_mutex_destroy(forks[i].check);
		pthread_mutex_destroy(p[i].R.check);
	}
	free(p->print);
	free(p->d_check);
	free(forks->fork);
	free(forks->check);
	free(forks);
	free(p);
}

int	error_mutexes(pthread_mutex_t *print, pthread_mutex_t *dead)
{
	if (print)
		free(print);
	if (dead)
		free(dead);
	printf("Error: malloc failed!\n");
	return (1);
}

int	error_forks(t_forks *forks, pthread_mutex_t *check)
{
	if (check)
		free(check);
	if (forks)
		free(forks);
	printf("Error: malloc failed!\n");
	return (1);
}