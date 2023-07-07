/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:17:49 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/07 23:25:19 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_nextorder(t_dlst *a_head, t_dlst *b_head)
{
	int	at;
	int	bh;
	int	bhn;
	int	bt;
	int	btp;

	if (b_head == NULL)
		return (0);
	at = ft_dlstlast(a_head)->index;
	bh = b_head->index;
	bhn = b_head->next->index;
	bt = ft_dlstlast(b_head)->index;
	btp = ft_dlstlast(b_head)->prev->index;
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

void	case_edge(t_dlst *stack_a[], int len)
{
	t_dlst	*tail;

	tail = ft_dlstlast(*stack_a);
	if ((*stack_a)->index - (*stack_a)->next->index == 1)
		swap(stack_a, 'a');
	else if ((*stack_a)->index - tail->index == 1)
		rerotate(stack_a, 'a');
	else
	{
		rerotate(stack_a, 'a');
		if (ft_issorted(stack_a, len) == 0)
			swap(stack_a, 'a');
	}
}

int	sort_small(t_dlst *stack_a[], t_dlst *stack_b[], int len, int *lens)
{
	while (ft_issorted(stack_a, len) == 0 && lens[2]++ < MAX_ITER)
	{
		if (lens[1] == 0)
			case_edge(stack_a, len);
		else if ((*stack_b)->next == NULL)
			push(stack_b, stack_a, 'a', lens);
		else if (ft_issorted(stack_a, lens[0]))
			nextorder_2(stack_a, stack_b, lens);
		else if (is_nextorder(*stack_a, *stack_b) == 1)
			rerotate(stack_a, 'a');
		else if (is_nextorder(*stack_a, *stack_b) == 2)
			nextorder_2(stack_a, stack_b, lens);
		else if (is_nextorder(*stack_a, *stack_b) == 3)
			nextorder_3(stack_a, stack_b, lens);
		else if (is_nextorder(*stack_a, *stack_b) == 4)
			nextorder_4(stack_a, stack_b, lens);
		else if (is_nextorder(*stack_a, *stack_b) == 5)
			nextorder_5(stack_a, stack_b, lens);
		else if ((*stack_b)->index > ft_dlstlast(*stack_a)->index)
			nextorder_2(stack_a, stack_b, lens);
		else if (is_nextorder(*stack_a, *stack_b) == 0)
			find_nextorder(stack_a, stack_b, lens);
	}
	return (0);
}
