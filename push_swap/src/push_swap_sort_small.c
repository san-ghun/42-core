/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_small.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:17:49 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/07 22:38:38 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nextorder_2(t_dlst *stack_a[], t_dlst *stack_b[], int *lens)
{
	push(stack_b, stack_a, 'a', lens);
	if ((*stack_a)->next->index - (*stack_a)->index != 1)
		rotate(stack_a, 'a');
	while ((*stack_a)->index - ft_dlstlast(*stack_a)->index == 1)
		rerotate(stack_a, 'a');
}

void	nextorder_3(t_dlst *stack_a[], t_dlst *stack_b[], int *lens)
{
	swap(stack_b, 'b');
	push(stack_b, stack_a, 'a', lens);
}

void	nextorder_4(t_dlst *stack_a[], t_dlst *stack_b[], int *lens)
{
	rerotate(stack_b, 'b');
	push(stack_b, stack_a, 'a', lens);
}

void	nextorder_5(t_dlst *stack_a[], t_dlst *stack_b[], int *lens)
{
	rerotate(stack_b, 'b');
	rerotate(stack_b, 'b');
	push(stack_b, stack_a, 'a', lens);
}

int	find_nextorder(t_dlst *stack_a[], t_dlst *stack_b[], int *lens)
{
	int	pos;

	pos = find_max(stack_b);
	if (pos == 0)
		return (0);
	if (pos <= (lens[1] / 2))
		while (pos--)
			rotate(stack_b, 'b');
	else
	{
		pos = lens[1] - pos;
		while (pos--)
			rerotate(stack_b, 'b');
	}
	push(stack_b, stack_a, 'a', lens);
	return (1);
}
