/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dlst_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:09:27 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/15 15:53:29 by sanghupa         ###   ########.fr       */
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

t_dlst	*ft_dlstlast(t_dlst *dlst)
{
	t_dlst *tmp;

	if (!dlst)
		return (0);
	tmp = dlst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
