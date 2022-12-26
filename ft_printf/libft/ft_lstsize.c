/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:41:01 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/13 13:46:15 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief count the number of nodes in a list.
/// @param lst the beginning of the list.
/// @return the length of the list.
int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	if (!lst)
		return (0);
	size = 1;
	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
