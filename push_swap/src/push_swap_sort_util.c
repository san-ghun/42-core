/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:17:49 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/06 17:43:29 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_presort(t_dlst *dlst[], int len, int i)
{
	int		length;
	t_dlst	*small;
	t_dlst	*large;
	t_dlst	*tmp;

	length = len - 1;
	while (i <= length)
	{
		tmp = *dlst;
		while (tmp->index != -1)
			tmp = tmp->next;
		small = tmp;
		large = tmp;
		while (tmp)
		{
			if (small->content > tmp->content && tmp->index == -1)
				small = tmp;
			if (large->content < tmp->content && tmp->index == -1)
				large = tmp;
			tmp = tmp->next;
		}
		small->index = i++;
		large->index = length--;
	}
}

int	ft_isordered(t_dlst *dlst[])
{
	int		i;
	t_dlst	*tmp;
	t_dlst	*next;

	i = 0;
	tmp = *dlst;
	if (tmp == NULL)
		return (1);
	next = tmp->next;
	while ((i++ <= MAX_ITER) && (next != NULL))
	{
		if (tmp->index > next->index)
			return (0);
		tmp = next;
		next = tmp->next;
	}
	return (1);
}

int	ft_issorted(t_dlst *dlst[], int len)
{
	int		i;
	t_dlst	*tmp;
	t_dlst	*next;

	if (!ft_isordered(dlst))
		return (0);
	i = 0;
	tmp = *dlst;
	if (tmp == NULL)
		return (0);
	next = tmp->next;
	while ((i++ <= MAX_ITER) && (next != NULL))
	{
		if (tmp->index > next->index)
			return (0);
		tmp = next;
		next = tmp->next;
	}
	if (len != i)
		return (0);
	return (1);
}

int	find_min(t_dlst *stack[])
{
	int		i;
	int		min;
	int		step;
	t_dlst	*tmp;

	i = 0;
	min = 0;
	step = 0;
	tmp = *stack;
	if (tmp == NULL)
		return (0);
	while ((i <= MAX_ITER) && (tmp->next != NULL))
	{
		if (tmp->index == min)
		{
			min = tmp->index;
			step = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (step);
}

int	find_max(t_dlst *stack[])
{
	int		i;
	int		max;
	int		step;
	t_dlst	*tmp;

	i = 0;
	max = 0;
	step = 0;
	tmp = *stack;
	if (tmp == NULL)
		return (0);
	max = tmp->index;
	while ((i <= MAX_ITER) && (tmp->next != NULL))
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			step = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (step);
}
