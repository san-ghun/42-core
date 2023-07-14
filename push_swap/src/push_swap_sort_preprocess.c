/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_preprocess.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:17:49 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/14 12:02:05 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_threshold(int len, double ratio)
{
	int	val;
	int	threshold;

	val = 10;
	if (len > 100)
		val += len / 25;
	threshold = 0;
	if ((len / val) <= 1)
		return (1);
	while (threshold < (len / val))
	{
		threshold += (int)(len * ratio);
		ratio += 0.005;
	}
	return (threshold);
}

void	distribute_stacks(
			t_dlst *stack_a[], 
			t_dlst *stack_b[], 
			int threshold, 
			int *lens
	)
{
	int		thres_0;
	int		len;
	int		len2;
	int		cnt;

	thres_0 = threshold;
	len = lens[0];
	while (threshold <= len)
	{
		cnt = 0;
		len2 = lens[0];
		while (++cnt < len2)
		{
			if (((*stack_a)->index) + 1 < threshold)
			{
				push(stack_a, stack_b, 'b', lens);
				rotate(stack_b, 'b');
			}
			else if (((*stack_a)->index) + 1 > (threshold + thres_0))
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b', lens);
		}
		threshold += thres_0 * 2;
	}
}

void	preprocess(t_dlst *stack_a[], t_dlst *stack_b[], int len, int *lens)
{
	int		maxi;
	int		threshold;
	double	ratio;

	maxi = len - 1;
	ratio = 0.01;
	threshold = set_threshold(len, ratio);
	distribute_stacks(stack_a, stack_b, threshold, lens);
	while (lens[0] > 1)
	{
		if ((*stack_a)->index == maxi)
			rotate(stack_a, 'a');
		push(stack_a, stack_b, 'b', lens);
	}
	if ((*stack_a)->index != maxi)
	{
		push(stack_a, stack_b, 'b', lens);
		while ((*stack_b)->index != maxi)
			rotate(stack_b, 'b');
		push(stack_b, stack_a, 'a', lens);
	}
}
