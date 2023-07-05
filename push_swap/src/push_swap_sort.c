/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:17:49 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/06 00:22:37 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_small(t_dlst *stack_a[], t_dlst *stack_b[], int len, int *lens)
{
	t_dlst	*a_tail;
	t_dlst	*b_tail;

	while (lens[1] > 0)
	{
		a_tail = ft_dlstlast(*stack_a);
		b_tail = ft_dlstlast(*stack_b);
		if (is_nextorder(*stack_a, a_tail, *stack_b, b_tail) == 1)
			rerotate(stack_a, 'a');
		if (is_nextorder(*stack_a, a_tail, *stack_b, b_tail) == 2)
			push(stack_b, stack_a, 'a', lens);
		if (is_nextorder(*stack_a, a_tail, *stack_b, b_tail) == 3)
			nextorder_3(stack_a, stack_b, lens);
		if (is_nextorder(*stack_a, a_tail, *stack_b, b_tail) == 4)
			nextorder_4(stack_a, stack_b, lens);
		if (is_nextorder(*stack_a, a_tail, *stack_b, b_tail) == 5)
			nextorder_4(stack_a, stack_b, lens);
		if (is_nextorder(*stack_a, a_tail, *stack_b, b_tail) == 0)
			find_nextorder(stack_a, stack_b, len, lens);
		// do something else
	}
	if (ft_issorted(stack_a, len))
		return (1);
	return (0);
}
