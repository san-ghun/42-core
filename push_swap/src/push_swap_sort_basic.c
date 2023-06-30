/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_basic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:17:49 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/30 23:54:36 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_dlst *dlst[], int ab)
{
	if (ft_isordered(dlst))
		return ;
	swap(dlst, ab);
}

void	sort_three(t_dlst *dlst[], int ab)
{
	t_dlst	*first;
	t_dlst	*second;
	t_dlst	*third;

	first = *dlst;
	second = first->next;
	third = second->next;
	if (ft_isordered(dlst))
		return ;
	if ((first->index > second->index) && (first->index > third->index))
	{
		rotate(dlst, ab);
		sort_three(dlst, ab);
	}
	else if (first->index > second->index)
	{
		swap(dlst, ab);
		sort_three(dlst, ab);
	}
	else if (second->index > third->index)
	{
		rerotate(dlst, ab);
		sort_three(dlst, ab);
	}
}

void	preprocess(t_dlst *stack_a[], t_dlst *stack_b[], int len, int *lens)
{
	int		cnt;
	// int		onoff;
	int		maxi;
	int		threshold;

	cnt = 0;
	// onoff = 0;
	maxi = len - 1;
	threshold = (int)(lens[0] * RATIO);
	while (threshold < lens[0])
	{
		cnt = 0;
		while (++cnt < lens[0])
		{
			if (((*stack_a)->index) + 1 < threshold && lens[1] >= 1)
			{
				push(stack_a, stack_b, 'b', lens);
				rotate(stack_b, 'b');
			}
			else if (((*stack_a)->index) + 1 > threshold)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b', lens);
		}
		threshold += (int)(len * (RATIO * 2));
	}
	while (lens[0] > 1)
	{
		if ((*stack_a)->index == maxi)
			rotate(stack_a, 'a');
		push(stack_a, stack_b, 'b', lens);
	}
}

// void	sort_four(t_dlst *stack_a[], t_dlst *stack_b[], int len, int *lens)
// {
// 	t_dlst	*tmp;

// 	tmp = *dlst;
// 	if (ft_issorted(stack_a, len))
// 		return ;
// 	if (ft_isordered(dlst))
// 		return ;
// }
