/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:23:56 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/11/29 17:25:13 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	checker(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' && argv[i][1])
			j++;
		while (argv[i][j] && (argv[i][j] <= '9' && argv[i][j] >= '0'))
			j++;
		if (argv[i][j])
		{
			printf("Needs to be a number you silly billy\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	processnum(int argc, char **argv, t_info *i)
{
	i->philo_nbr = ft_atoi_phil(argv[1]);
	i->tt_d = ft_atoi_phil(argv[2]);
	i->tt_e = ft_atoi_phil(argv[3]);
	i->tt_s = ft_atoi_phil(argv[4]);
	i->st = clock();
	if (argc == 6)
		i->philo_eat = ft_atoi_phil(argv[5]);
	else
		i->philo_eat = -3;
	if (!i->philo_nbr || !i->tt_d|| !i->tt_d || !i->philo_eat || !i->tt_e)
	{
		printf("0 < num < 2147483648 UwU\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	i;
	t_forks	*f;
	t_philo	*p
	
	if (argc != 5 && argc != 6)
	{
		printf("Whoopsie, you did an upsie\n");
		return (1);
	}
	if (checker(argc, argv) == 1 || processnum(argc,argv, &p) != 0)
		return (1);
	if (!create_forks(&f, i.philo_nbr))
		return (1);
	init_mutex(p, i.philo_nbr)
}