/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dlst_read.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:54:12 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/15 23:38:10 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlst	*ft_dlstget(t_dlst *dlst[], void *content)
{
	int		i;
	t_dlst	*tmp;

	i = 0;
	tmp = *dlst;
	while ((i++ <= MAX_ITER) || (tmp->next != NULL))
	{
		if (tmp->content == &content)
			return (tmp);
	}
	return (NULL);
}