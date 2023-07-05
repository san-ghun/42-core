/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_small.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:17:49 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/05 17:31:33 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max3(t_dlst *a_tail, t_dlst *b_head, t_dlst *b_tail)
{
	int	at;
	int	bh;
	int	bt;

	at = a_tail->index;
	bh = b_head->index;
	bt = b_tail->index;
	if ((at > bh) && (at > bt))
		return (1);
	if ((bh > at) && (bh > bt))
		return (2);
	if ((bt > at) && (bt > bh))
		return (3);
	return (0);
}

int	find_max4(t_dlst *a_head, t_dlst *a_tail, t_dlst *b_head, t_dlst *b_tail)
{
	int	ah;
	int	at;
	int	bh;
	int	bt;

	ah = a_head->index;
	at = a_tail->index;
	bh = b_head->index;
	bt = b_tail->index;
	if ((ah > at) && (ah > bh) && (ah > bt))
		return (1);
	if ((at > ah) && (at > bh) && (at > bt))
		return (2);
	if ((bh > ah) && (bh > at) && (bh > bt))
		return (3);
	if ((bt > ah) && (bt > at) && (bt > bh))
		return (4);
	return (0);
}

int	is_nextorder(t_dlst *a_head, t_dlst *a_tail, t_dlst *b_head, t_dlst *b_tail)
{
	int	ah;
	int	at;
	int	bh;
	int	bhn;
	int	bt;

	ah = a_head->index;
	at = a_tail->index;
	bh = b_head->index;
	bhn = b_head->next->index;
	bt = b_tail->index;
	if (ah - at == 1)
		return (1);
	if (ah - bh == 1)
		return (2);
	if (ah - bhn == 1)
		return (3);
	if (ah - bt == 1)
		return (4);
	return (5);
}

int	find_nextorder(t_dlst *stack_a[], t_dlst *stack_b[], int len, int *lens)
{
	
}

int	sort_small(t_dlst *stack_a[], t_dlst *stack_b[], int len, int *lens)
{
	int		i;
	t_dlst	*a_head;
	t_dlst	*a_tail;
	t_dlst	*b_head;
	t_dlst	*b_tail;

	while (lens[1] > 0)
	{
		a_head = *stack_a;
		a_tail = ft_dlstlast(a_head);
		b_head = *stack_b;
		b_tail = ft_dlstlast(b_head);
		if (is_nextorder(a_head, a_tail, b_head, b_tail) == 1)
			rerotate(stack_a, 'a');
		if (is_nextorder(a_head, a_tail, b_head, b_tail) == 2)
			push(stack_b, stack_a, 'a', lens);
		if (is_nextorder(a_head, a_tail, b_head, b_tail) == 3)
		{
			swap(stack_b, 'b');
			push(stack_b, stack_a, 'a', lens);
		}
		if (is_nextorder(a_head, a_tail, b_head, b_tail) == 4)
		{
			rerotate(stack_b, 'b');
			push(stack_b, stack_a, 'a', lens);
		}
		if (is_nextorder(a_head, a_tail, b_head, b_tail) == 5)
		{} // TODO: !
		// do something else
	}
	if (ft_issorted(stack_a, len))
		return (1);
	return (0);
}
