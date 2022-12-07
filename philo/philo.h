/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:22:12 by pcoimbra          #+#    #+#             */
/*   Updated: 2022/12/07 19:08:03 by pcoimbra         ###   ########.fr       */
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
	int				fork;
	pthread_mutex_t	*check;
}					t_forks;

typedef struct s_info
{
	int				philo_nbr;
	unsigned long	tt_d;
	int				tt_e;
	int				tt_s;
	int				philo_eat;
	unsigned long	st;
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

int				ft_atoi_phil(const char *str);
unsigned long	time_philo(void);
unsigned long	time_now(t_philo *p);

//	routine.c

void	*philo_stuff(void *philo);

//	routine_utils.c

int	checker_deader(t_philo *p);
int	xonar(t_philo *philo, unsigned long time);
int	yeeat(t_philo *p);

//	routine_utils1.c

void	philo_print(t_philo *p, char *str);
void	print_eat(t_philo *p);

#endif