/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dlst_read.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:54:12 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/20 00:06:28 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlst	*ft_dlstget(t_dlst *dlst[], int content)
{
	int		i;
	t_dlst	*tmp;

	if (!dlst || !(*dlst))
		return (NULL);
	i = 0;
	tmp = *dlst;
	while ((i++ <= MAX_ITER) || (tmp->next != NULL))
	{
		if (tmp->content == content)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
