/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_small.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:17:49 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/06 11:13:31 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	find_max3(t_dlst *a_tail, t_dlst *b_head, t_dlst *b_tail)
// {
// 	int	at;
// 	int	bh;
// 	int	bt;

// 	at = a_tail->index;
// 	bh = b_head->index;
// 	bt = b_tail->index;
// 	if ((at > bh) && (at > bt))
// 		return (1);
// 	if ((bh > at) && (bh > bt))
// 		return (2);
// 	if ((bt > at) && (bt > bh))
// 		return (3);
// 	return (0);
// }

// int	find_max4(t_dlst *a_head, t_dlst *a_tail, t_dlst *b_head, t_dlst *b_tail)
// {
// 	int	ah;
// 	int	at;
// 	int	bh;
// 	int	bt;

// 	ah = a_head->index;
// 	at = a_tail->index;
// 	bh = b_head->index;
// 	bt = b_tail->index;
// 	if ((ah > at) && (ah > bh) && (ah > bt))
// 		return (1);
// 	if ((at > ah) && (at > bh) && (at > bt))
// 		return (2);
// 	if ((bh > ah) && (bh > at) && (bh > bt))
// 		return (3);
// 	if ((bt > ah) && (bt > at) && (bt > bh))
// 		return (4);
// 	return (0);
// }

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
	int	i;
	int	pos;

	i = 0;
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
