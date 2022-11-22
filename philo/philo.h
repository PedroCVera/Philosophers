/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:22:12 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/11/22 14:32:30 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_info
{
	int	philo_count;
	int	tt_d;
	int	tt_e;
	int	tt_s;
	int	philo_eat;
	int	st;
}		t_info;

typedef struct s_philo
{
	int		ate;
	int		last_ate;
	t_info	info;
}		t_philo;

int	ft_atoi(const char *str);
int	clock(void);

#endif