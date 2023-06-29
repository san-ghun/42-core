/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:18:01 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/29 15:57:57 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_dlst *stack[], int ab)
{
	t_dlst	*head;
    t_dlst  *newhead;

	if (!stack || !(*stack))
		return ;
	head = *stack;
    if (head->next == NULL)
        return ;
    newhead = head->next;
	head->prev = newhead;
    head->next = newhead->next;
    newhead->next->prev = head;
    newhead->next = head;
    *stack = newhead;
    newhead->prev = NULL;
    if (ab == 'a')
        ft_printf("sa\n");
    else if (ab == 'b')
        ft_printf("sb\n");
}

void    push(t_dlst *stack_from[], t_dlst *stack_to[], int ab)
{
	t_dlst  *popped;

    if (!stack_from || !(*stack_from))
		return ;
    popped = ft_pop(stack_from);
    if (!popped)
        return ;
    ft_dlstadd_front(stack_to, popped);
    if (ab == 'a')
        ft_printf("pa\n");
    else if (ab == 'b')
        ft_printf("pb\n");
    else
        ft_printf("push what?");
}

void    rotate(t_dlst *stack[], int ab)
{
	t_dlst  *popped;

    if (!stack || !(*stack))
		return ;
    popped = ft_pop(stack);
    ft_dlstadd_back(stack, popped);
    if (ab == 'a')
        ft_printf("ra\n");
    else if (ab == 'b')
        ft_printf("rb\n");
}

void    rerotate(t_dlst *stack[], int ab)
{
	t_dlst	*head;
    t_dlst  *newhead;

	if (!stack || !(*stack))
		return ;
	head = *stack;
    newhead = ft_dlstlast(*stack);
	head->prev = newhead;
    newhead->next = head;
    *stack = newhead;
    newhead->prev->next = NULL;
    newhead->prev = NULL;
    if (ab == 'a')
        ft_printf("rra\n");
    else if (ab == 'b')
        ft_printf("rrb\n");
}

void    ss(t_dlst *stack_a[], t_dlst *stack_b[])
{
    swap(stack_a, 0);
    swap(stack_b, 0);
    ft_printf("ss\n");
}

void    rr(t_dlst *stack_a[], t_dlst *stack_b[])
{
    rotate(stack_a, 0);
    rotate(stack_b, 0);
    ft_printf("rr\n");
}

void    rrr(t_dlst *stack_a[], t_dlst *stack_b[])
{
    rerotate(stack_a, 0);
    rerotate(stack_b, 0);
    ft_printf("rrr\n");
}
