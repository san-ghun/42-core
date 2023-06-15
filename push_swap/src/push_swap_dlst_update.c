/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dlst_update.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:03:41 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/15 23:19:26 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstupdate(t_dlst *dlst[], void *old, void *new)
{
	t_dlst	*tmp;

	tmp = ft_dlstget(dlst, old);
	if (!tmp)
		return ;
	tmp->content = new;
}
