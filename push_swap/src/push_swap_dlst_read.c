/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dlst_read.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:54:12 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/15 17:59:28 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlst	*ft_dlstget(t_dlst *dlst, void *content)
{
	int	i;

	i = 0;
	while ((i++ <= MAX_ITER) || (dlst->next != NULL))
	{
		if (dlst->content == &content)
			return (dlst);
	}
	return (NULL);
}