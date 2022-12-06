/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:22:12 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/12/05 17:22:49 by pcoimbra         ###   ########.fr       */
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

typedef struct s_fork
{
	int				*fork;
	pthread_mutex_t	*check;
}					t_forks;

typedef struct s_info
{
	int	philo_nbr;
	int	tt_d;
	int	tt_e;
	int	tt_s;
	int	philo_eat;
	int	st;
}		t_info;

typedef struct s_philo
{
	pthread_t		id;
	unsigned long	t_start;
	unsigned long	last_eat;
	int				times_eat;
	int				nbr;
	t_forks			R;
	t_forks			L;
	pthread_mutex_t	*print;
	pthread_mutex_t	*d_check;
	int				*dead;
	t_info			*data;
}					t_philo;



//	srcs/checker.c

int	processnum(int argc, char **argv, t_info *i);
int	checker(int argc, char **argv);

//	srcs/init_philo.c

int	create_forks(t_forks **forks, int philo_nbr);
int	philo_init(t_forks **f, t_info *i, t_philo **p, int *dead);

//	utils/utils1.c

int	ft_atoi_phil(const char *str);
int	time_philo(void);

//	routine.c

void	*philo_stuff(void *philo);

#endif