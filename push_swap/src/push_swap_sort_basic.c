/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_basic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:17:49 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/06 00:14:02 by sanghupa         ###   ########.fr       */
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
