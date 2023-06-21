/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dlst_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:09:27 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/21 20:36:29 by sanghupa         ###   ########.fr       */
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
	if (!dlst)
		return (NULL);
	while (dlst->next != NULL)
		dlst = dlst->next;
	return (dlst);
}

void	ft_dlstprint(t_dlst *dlst[])
{
	int		i;
	t_dlst	*tmp;

	i = 0;
	tmp = *dlst;
	if (tmp == NULL)
		ft_printf("dlst is empty");
	while ((i++ <= MAX_ITER) && (tmp != NULL))
	{
		ft_printf("%X-%d-%X ", tmp->prev, tmp->content, tmp->next);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
