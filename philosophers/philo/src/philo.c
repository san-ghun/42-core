/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:07:53 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/06 00:15:48 by sanghupa         ###   ########.fr       */
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
		eat(philo->id, philo->left, philo->right);
		// jam(id);
		think(philo->id);
		meals--;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int				i;
	t_resource		*rsc;

	if (check_args(argc, argv) != 0)
		return (1);
	rsc = init_resource(ft_atoi(argv[1]), ft_atoi(argv[2]), \
						ft_atoi(argv[3]), ft_atoi(argv[4]));
	if (argc == 6)
		rsc->n_eat_opt = ft_atoi(argv[5]);
	i = -1;
	while (++i < rsc->n_philos)
	{
		pthread_create(rsc->philosophers[i], NULL, philosopher, rsc->philos[i]);
	}
	i = -1;
	while (++i < rsc->n_philos)
		pthread_join(*(rsc->philosophers[i]), NULL);
	free_resource();
	return (0);
}
