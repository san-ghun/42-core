/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_resource.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:46:48 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/20 20:59:38 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_resource	*single_rsc(void)
{
	static t_resource	this;
	static int			is_init;

	if (is_init)
		return (&this);
	this = (t_resource){
		.n_philos = 0,
		.time_die = 0,
		.time_eat = 0,
		.time_jam = 0,
		.n_eat_opt = -1,
		.philos = NULL,
		.forks = NULL,
		.printlock = NULL,
		.eatlock = NULL,
		.deadlock = NULL,
		.n_done = 0,
		.funeral = 0,
	};
	is_init = 1;
	return (&this);
}

void	free_rsc_arr(t_resource *rsc)
{
	int	i;

	i = -1;
	while (++i < rsc->n_philos)
		free(rsc->philos[i]);
	sem_close(rsc->forks);
	sem_unlink(SEM_FORKS);
	return ;
}

void	free_resource(void)
{
	t_resource	*rsc;

	rsc = single_rsc();
	free_rsc_arr(rsc);
	sem_close(rsc->printlock);
	sem_unlink(SEM_PLOCK);
	sem_close(rsc->eatlock);
	sem_unlink(SEM_ELOCK);
	sem_close(rsc->deadlock);
	sem_unlink(SEM_DLOCK);
	free(rsc->philos);
	return ;
}
