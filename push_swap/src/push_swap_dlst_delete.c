/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dlst_delete.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:07:08 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/19 01:11:35 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstdelone(t_dlst *dlst)
{
	if (!dlst)
		return ;
	if (dlst->next != NULL)
		dlst->next->prev = dlst->prev;
	if (dlst->prev != NULL)
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
	while (tmp != NULL)
	{
		ft_putchar_fd('0', 1);
		after = tmp->next;
		ft_dlstdelone(tmp);
		tmp = after;
	}
	return ;
}
