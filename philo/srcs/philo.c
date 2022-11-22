/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:23:56 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/11/22 14:30:33 by pcoimbra         ###   ########.fr       */
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

int	processnum(int argc, char **argv, t_info *p)
{
	p->philo_count = ft_atoi(argv[1]);
	p->tt_d = ft_atoi(argv[2]);
	p->tt_e = ft_atoi(argv[3]);
	p->tt_s = ft_atoi(argv[4]);
	p->st = clock();
	if (argc == 6)
		p->philo_eat = ft_atoi(argv[5]);
	else
		p->philo_eat = -3;
	if (!p->philo_count|| !p->tt_d|| !p->tt_d || !p->philo_eat || !p->tt_e)
	{
		printf("0 < num < 2147483648 UwU\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	p;
	
	if (argc != 5 && argc != 6)
	{
		printf("Whoopsie, you did an upsie\n");
		return (1);
	}
	if (checker(argc, argv) == 1 || processnum(argc,argv, &p) != 0)
		return (1);
	
}