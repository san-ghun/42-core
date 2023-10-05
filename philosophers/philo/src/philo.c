/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:07:53 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/05 17:49:00 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO: implement
void	*philosopher(t_philo *philo)
{
	size_t	meals;

	meals = resource_singleton()->n_eat_opt;
	while (meals > 0)
	{
		think(philo->id);
		eat(philo->id, philo->left, philo->right);
		// jam(id);
		meals--;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int				i;
	size_t			n_philo;
	t_resource		*rsc;

	if ((argc < 5) || (argc > 6))
		return (err_invalid_args());
	n_philo = ft_atoi(argv[1]);
	rsc = init_resource(n_philo, ft_atoi(argv[2]), \
						ft_atoi(argv[3]), ft_atoi(argv[4]));
	if (argc == 6)
		rsc->n_eat_opt = ft_atoi(argv[5]);
	i = -1;
	while (++i < n_philo)
	{
		pthread_create(rsc->philosophers[i], NULL, \
					(void *)philosopher, rsc->philos[i]);
	}
	i = -1;
	while (++i < n_philo)
		pthread_join(*(rsc->philosophers[i]), NULL);
	free_resource();
	// i = -1;
	// n_philo = rsc->n_philos;
	// while (++i < n_philo)
	// {
	// 	free(rsc->philosophers[i]);
	// 	free(rsc->forks[i]);
	// 	free(rsc->philos[i]);
	// }
	// free(rsc->philos);
	// free(rsc->philosophers);
	// free(rsc->forks);
	// free(rsc->printlock);
	return (0);
}
