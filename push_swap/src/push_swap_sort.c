/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:17:49 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/29 23:03:32 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: do presort and save the order to index
void	ft_presort(t_dlst *dlst[], int len, int i)
{
	t_dlst	*small;
	t_dlst	*large;
	t_dlst	*tmp;

	len--;
	while (i <= len)
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
		large->index = len--;
	}
}
