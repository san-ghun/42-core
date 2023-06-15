/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dlst_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:09:25 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/15 23:44:49 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlst	*ft_dlstnew(void *content)
{
	t_dlst	*new;

	new = (t_dlst *)malloc(sizeof(t_dlst));
	if (!new)
		return (NULL);
	new->prev = 0;
	new->content = content;
	new->next = 0;
	return (new);
}

t_dlst	**init_dlst(void)
{
	t_dlst	*head;
	t_dlst	*tail;

	head = ft_dlstnew(NULL);
	tail = ft_dlstnew(NULL);
	head->next = tail;
	tail->prev = head;
	return (head);
}

void	ft_dlstadd_front(t_dlst *dlst[], t_dlst *new)
{
	t_dlst	*head;

	head = *dlst;
	if (!dlst || !new || !head)
		return ;
	new->next = head->next;
	head->next = new;
	new->prev = new->next->prev;
	new->next->next = new;
}

void	ft_dlstadd_back(t_dlst *dlst[], t_dlst *new)
{
	t_dlst	*tail;

	tail = ft_dlstlast(*dlst);
	if (!dlst || !new || !tail)
		return ;
	new->prev = tail->prev;
	tail->prev = new;
	new->next = new->prev->next;
	new->prev->next = new;
}
