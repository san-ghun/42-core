/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dlst_delete.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:07:08 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/21 20:58:16 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstdelone(t_dlst *dlst[], t_dlst *elem)
{
	t_dlst	*tmp;

	if (!dlst || !elem)
		return ;
	if ((elem->prev == NULL) && (elem->next == NULL))
	{
		tmp = *dlst;
		*dlst = NULL;
		return (free(elem));
	}
	else if (elem->next == NULL)
		elem->prev->next = NULL;
	else if (elem->prev == NULL)
	{
		elem->next->prev = NULL;
		*dlst = elem->next;
	}
	else
	{
		elem->prev->next = elem->next;
		elem->next->prev = elem->prev;
	}
	free(elem);
	return ;
}

t_dlst	*ft_pop(t_dlst *stack[])
{
	t_dlst	*dlst;

	if (!stack)
		return (NULL);
	dlst = *stack;
	if (dlst->prev != NULL)
	{
		ft_printf("FAIL: the stack is wrong - you should not have prev node\n");
		return (NULL);
	}
	dlst->next->prev = NULL;
	*stack = dlst->next;
	return (dlst);
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
		after = tmp->next;
		ft_dlstdelone(dlst, tmp);
		tmp = after;
	}
	ft_printf("\n");
	return ;
}
