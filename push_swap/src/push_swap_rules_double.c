/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_double.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:18:01 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/29 23:50:18 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_dlst *stack_a[], t_dlst *stack_b[])
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	ft_printf("ss\n");
}

void	rr(t_dlst *stack_a[], t_dlst *stack_b[])
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	ft_printf("rr\n");
}

void	rrr(t_dlst *stack_a[], t_dlst *stack_b[])
{
	rerotate(stack_a, 0);
	rerotate(stack_b, 0);
	ft_printf("rrr\n");
}
