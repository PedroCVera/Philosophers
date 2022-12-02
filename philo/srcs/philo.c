/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:23:56 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/12/02 17:16:53 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
	if (checker(argc, argv) == 1 || processnum(argc,argv, &p) != 0)
		return (1);
	if (!create_forks(&f, i.philo_nbr))
		return (1);
	create_forks(&f, i.philo_nbr);
	philo_init(&f, &i, &p, &dead);
	ind = -1;
	while (++ind < i.philo_nbr)
		pthread_join(p[ind].id, NULL);
//	end_free(p, f, i);
}