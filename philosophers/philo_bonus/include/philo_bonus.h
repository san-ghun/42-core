/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:07:55 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/20 18:16:13 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
# include <semaphore.h>

// Limit Loop: use addition to while condition
# define MAX_ITER	5000

// Prevent Heap mem leak: use addition to char or array
# define DATA_SIZE	3072

# define SEM_FORKS	"/philo_forks"
# define SEM_PLOCK	"/philo_printlock"
# define SEM_ELOCK	"/philo_eatlock"
# define SEM_DLOCK	"/philo_deatlock"

typedef struct s_philo
{
	int			id;
	pid_t		pid;
	int			n_ate;
	int			status;
	long long	t_launch;
	long long	t_last_meal;
}				t_philo;

typedef struct s_resource
{
	int			n_philos;
	long long	time_die;
	long long	time_eat;
	long long	time_jam;
	int			n_eat_opt;
	t_philo		**philos;
	sem_t		*forks;
	sem_t		*printlock;
	sem_t		*eatlock;
	sem_t		*deadlock;
	int			n_done;
	int			funeral;
}				t_resource;

/* philo_bonus.c */

/* philo_bonus_resource.c */
t_resource	*single_rsc(void);
void		free_resource(void);

/* philo_bonus_init.c */
t_resource	*init_resource(int n_philo, int t_die, int t_eat, int t_jam);

/* philo_bonus_routine.c */
void		*check_status(t_philo *philo);
void		eat(t_philo *philo, t_resource *rsc);
void		jam(t_philo *philo, t_resource *rsc);
void		think(t_philo *philo, t_resource *rsc);
int			die(t_philo *philo, t_resource *rsc);

/* philo_bonus_util.c */
int			check_args(int argc, char *argv[]);
int			ft_atoi(const char *str);
long long	get_time_ms(void);
void		print_status(t_philo *philo, t_resource *rsc, char *str);
void		print_dead(t_philo *philo, t_resource *rsc);

#endif
