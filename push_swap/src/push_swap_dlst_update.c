/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dlst_update.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:03:41 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/16 23:21:29 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstupdate(t_dlst *dlst[], int old, int new)
{
	t_dlst	*tmp;

	tmp = ft_dlstget(dlst, old);
	if (!tmp)
		return ;
	tmp->content = new;
}
