/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:59:10 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/13 14:07:51 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief take as a parameter a node and free the memory of 
/// the node's content using the function `del` 
/// given as a parameter and free the node.
/// The memory of `next` must not be freed.
/// @param lst the node to free.
/// @param del the address of the functioin used to delete the content.
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
