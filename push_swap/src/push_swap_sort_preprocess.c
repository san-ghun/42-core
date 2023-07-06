/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_preprocess.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:17:49 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/06 17:08:29 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_threshold(int len, double ratio)
{
	int	threshold;

	threshold = 0;
	if ((len / 10) <= 1)
		return (1);
	while (threshold < (len / 10))
	{
		threshold += (int)(len * ratio);
		ratio += 0.02;
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
	int	i;
	int	cnt;
	int	len;

	len = ft_dlstsize(*stack_a);
	while (threshold <= len)
	{
		i = lens[0];
		cnt = 0;
		while (++cnt < i)
		{
			if (((*stack_a)->index) + 1 < threshold)
			{
				push(stack_a, stack_b, 'b', lens);
				rotate(stack_b, 'b');
			}
			else if (((*stack_a)->index) + 1 > (threshold * 2))
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b', lens);
		}
		threshold *= 2.9;
	}
}
// {
// 	int	i;
// 	int	cnt;

// 	while (threshold <= len)
// 	{
// 		i = lens[0];
// 		cnt = 0;
// 		while (++cnt < i)
// 		{
// 			if (((*stack_a)->index) + 1 < threshold)
// 			{
// 				push(stack_a, stack_b, 'b', lens);
// 				rotate(stack_b, 'b');
// 			}
// 			else if (((*stack_a)->index) + 1 <= (threshold * 2))
// 			{
// 				push(stack_a, stack_b, 'b', lens);
// 			}
// 			else if (((*stack_a)->index) + 1 > (threshold * 2))
// 			// else
// 			{
// 				printf("%d\n", threshold);
// 				rotate(stack_a, 'a');
// 			}	
// 		}
// 		threshold = threshold + 0.24 * 100;
// 	}
// }

void	preprocess(t_dlst *stack_a[], t_dlst *stack_b[], int len, int *lens)
{
	int		maxi;
	int		threshold;
	double	ratio;

	maxi = len - 1;
	ratio = 0.01;
	threshold = set_threshold(len, ratio);
	// ratio = 0.12;
	// threshold = len * ratio;
	// ft_printf("threshold = %d\n", threshold);
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
