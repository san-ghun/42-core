/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:07:52 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/11 10:30:38 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

// Limit Loop: use addition to while condition
# define MAX_ITER	5000

// Prevent Heap mem leak: use addition to char or array
# define DATA_SIZE	3072

typedef struct s_philo
{
	int				id;
	int				n_ate;
	int				status;
	long long		t_launch;
	long long		t_last_meal;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}					t_philo;

typedef struct s_resource
{
	int				n_philos;
	long long		time_die;
	long long		time_eat;
	long long		time_jam;
	int				n_eat_opt;
	t_philo			**philos;
	pthread_t		**philosophers;
	pthread_mutex_t	**forks;
	pthread_mutex_t	*printlock[5];
	pthread_mutex_t	*rip;
	int				funeral;
}					t_resource;

/* philo.c */
int			check_status(t_resource *rsc);

/* philo_resource.c */
t_resource	*single_rsc(void);
void		free_resource(void);

/* philo_init.c */
t_resource	*init_resource(int n_philo, int t_die, int t_eat, int t_jam);

/* philo_routine.c */
void		eat(t_philo *philo, t_resource *rsc);
void		jam(t_philo *philo, t_resource *rsc);
void		think(t_philo *philo, t_resource *rsc);
int			die(t_philo *philo, t_resource *rsc);

/* philo_util.c */
int			check_args(int argc, char *argv[]);
int			ft_atoi(const char *str);
long long	get_time_ms(void);
void		print_status(t_philo *philo, t_resource *rsc, char *str, int nlock);
void		print_dead(t_philo *philo, t_resource *rsc);

#endif
