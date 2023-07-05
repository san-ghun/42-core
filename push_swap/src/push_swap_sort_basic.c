/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_basic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:17:49 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/05 17:20:16 by sanghupa         ###   ########.fr       */
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
			int len,
			int *lens
	)
{
	int	i;
	int	cnt;

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
			{
				printf("%d\n", threshold);
				rotate(stack_a, 'a');
			}	
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
	ft_printf("threshold = %d\n", threshold);
	distribute_stacks(stack_a, stack_b, threshold, len, lens);
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
