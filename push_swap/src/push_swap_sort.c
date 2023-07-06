/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:17:49 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/06 12:22:06 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_nextorder(t_dlst *a_head, t_dlst *a_tail, t_dlst *b_head, t_dlst *b_tail)
{
	int	at;
	int	bh;
	int	bhn;
	int	bt;
	int	btp;

	at = a_tail->index;
	bh = b_head->index;
	bhn = b_head->next->index;
	bt = b_tail->index;
	btp = b_tail->prev->index;
	if (a_head->index - at == 1)
		return (1);
	if (a_head->index - bh == 1)
		return (2);
	if (a_head->index - bhn == 1)
		return (3);
	if (a_head->index - bt == 1)
		return (4);
	if (a_head->index - btp == 1)
		return (5);
	return (0);
}

int	sort_small(t_dlst *stack_a[], t_dlst *stack_b[], int len, int *lens)
{
	t_dlst	*a_tail;
	t_dlst	*b_tail;

	while (ft_issorted(stack_a, len) == 0)
	{
		a_tail = ft_dlstlast(*stack_a);
		b_tail = ft_dlstlast(*stack_b);
		if (b_tail == *stack_b)
			push(stack_b, stack_a, 'a', lens);
		else if (is_nextorder(*stack_a, a_tail, *stack_b, b_tail) == 1)
			rerotate(stack_a, 'a');
		else if (is_nextorder(*stack_a, a_tail, *stack_b, b_tail) == 2)
			push(stack_b, stack_a, 'a', lens);
		else if (is_nextorder(*stack_a, a_tail, *stack_b, b_tail) == 3)
			nextorder_3(stack_a, stack_b, lens);
		else if (is_nextorder(*stack_a, a_tail, *stack_b, b_tail) == 4)
			nextorder_4(stack_a, stack_b, lens);
		else if (is_nextorder(*stack_a, a_tail, *stack_b, b_tail) == 5)
			nextorder_5(stack_a, stack_b, lens);
		else if (is_nextorder(*stack_a, a_tail, *stack_b, b_tail) == 0)
			find_nextorder(stack_a, stack_b, lens);
	}
	if (ft_issorted(stack_a, len))
		return (1);
	return (0);
}
