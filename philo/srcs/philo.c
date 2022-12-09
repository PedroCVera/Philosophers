/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:23:56 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/12/09 16:57:56 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

#include "../philo.h"

void	*philo_stuff(void *cenas)
{
	t_philo *p;

	p = (t_philo *)cenas;
	p->last_eat = 0;
	if (!(p->nbr % 2))
		usleep(10000);
	while (checker_deader(p) == 0)
	{
		yeeat(p);
		if (p->data->philo_eat != -3 && p->times_eat == p->data->philo_eat)
			break ;
		if (checker_deader(p) == 0)
			philo_print(p, "is sleeping");
		xonar(p, p->data->tt_s);
		if (checker_deader(p) == 0)
			philo_print(p, "is sleeping");
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_info	i;
	t_forks	*f;
	t_philo	*p;
	int		dead;
	int		ind;
	
	dead = 0;
	if (argc != 5 && argc != 6)
	{
		printf("Whoopsie, you did an upsie\n");
		return (1);
	}
	if (checker(argc, argv) == 1 || processnum(argc, argv, &i) != 0)
		return (1);
	if (create_forks(&f, i.philo_nbr))
		return (1);
	philo_init(&f, &i, &p, &dead);
	ind = -1;
	while (++ind < i.philo_nbr)
		pthread_join(p[ind].id, NULL);
//	end_free(p, f, i);
}