/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_basic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:17:49 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/06 17:53:24 by sanghupa         ###   ########.fr       */
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

void	sort_four(t_dlst *stack_a[], t_dlst *stack_b[], int *lens)
{
	int	i;
	int	pos;

	i = 0;
	pos = find_min(stack_a);
	if (pos == 0)
		push(stack_a, stack_b, 'b', lens);
	else if (pos <= (lens[0] / 2))
	{
		while (pos--)
			rotate(stack_a, 'a');
		push(stack_a, stack_b, 'b', lens);
	}
	else
	{
		pos = lens[0] - pos;
		while (pos--)
			rerotate(stack_a, 'a');
		push(stack_a, stack_b, 'b', lens);
	}
	sort_three(stack_a, 'a');
	push(stack_b, stack_a, 'a', lens);
	return ;
}
