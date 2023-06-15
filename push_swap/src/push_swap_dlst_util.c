/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dlst_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:09:27 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/15 23:45:04 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_dlstsize(t_dlst *dlst)
{
	int		size;
	t_dlst	*tmp;

	if (!dlst)
		return (0);
	size = 1;
	tmp = dlst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

// TODO: *dlst or *dlst[] ?
t_dlst	*ft_dlstlast(t_dlst *dlst[])
{
	t_dlst	*tmp;

	if (!dlst)
		return (0);
	tmp = *dlst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_dlstprint(t_dlst *dlst[])
{
	int		i;
	t_dlst	*tmp;

	i = 0;
	tmp = *dlst;
	while ((i++ <= MAX_ITER) || (tmp->next != NULL))
		ft_printf("%d\n", tmp->content);
	return ;
}
