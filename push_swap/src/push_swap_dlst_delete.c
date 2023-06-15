/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dlst_delete.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:07:08 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/15 23:47:15 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstdelone(t_dlst *dlst)
{
	if (!dlst)
		return ;
	dlst->next->prev = dlst->prev;
	dlst->prev->next = dlst->next;
	free(dlst);
	return ;
}

void	ft_dlstclear(t_dlst *dlst[])
{
	t_dlst	*tmp;
	t_dlst	*after;

	if (!dlst)
		return ;
	tmp = *dlst;
	*dlst = NULL;
	while (tmp->next != NULL)
	{
		after = tmp->next;
		ft_dlstdelone(tmp);
		tmp = after;
	}
	return ;
}
