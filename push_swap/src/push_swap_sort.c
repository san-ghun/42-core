/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:17:49 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/07 17:36:52 by sanghupa         ###   ########.fr       */
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

	bh = -1;
	bhn = -1;
	btp = -1;
	at = ft_dlstlast(a_head)->index;
	if (b_head != NULL)
		bh = b_head->index;
	if (b_head->next != NULL)
		bhn = b_head->next->index;
	if (b_head != NULL)
		bt = ft_dlstlast(b_head)->index;
	if (ft_dlstlast(b_head)->prev != NULL)
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

int	sort_small(t_dlst *stack_a[], t_dlst *stack_b[], int len, int *lens)
{
	// while (ft_issorted(stack_a, len) == 0)
	while (lens[1] > 0)
	{
		if ((*stack_b)->next == NULL)
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
	if (is_nextorder(*stack_a, *stack_b) == 1)
		rerotate(stack_a, 'a');
	if (ft_issorted(stack_a, len))
		return (1);
	return (0);
}
