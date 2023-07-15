/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dlst_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:09:25 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/20 00:25:51 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlst	*ft_dlstnew(int content)
{
	t_dlst	*new;

	new = (t_dlst *)malloc(sizeof(t_dlst));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->content = content;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_dlstadd_front(t_dlst *dlst[], t_dlst *new)
{
	t_dlst	*head;

	head = *dlst;
	if (!dlst || !new)
		return ;
	if (!head)
	{
		*dlst = new;
		new->prev = NULL;
		new->next = NULL;
		return ;
	}
	head->prev = new;
	new->next = head;
	*dlst = new;
	new->prev = NULL;
}

void	ft_dlstadd_back(t_dlst *dlst[], t_dlst *new)
{
	t_dlst	*tail;

	if (!dlst || !new)
		return ;
	tail = ft_dlstlast(*dlst);
	if (!tail)
	{
		*dlst = new;
		new->prev = NULL;
		new->next = NULL;
		return ;
	}
	tail->next = new;
	new->prev = tail;
	new->next = NULL;
}
