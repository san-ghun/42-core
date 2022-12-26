/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:28:46 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/13 19:55:33 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief iterate the list `lst` and apply the function `f` 
/// to the content of each node. Create a new list resulting 
/// of the successive applications of the function `f`.
/// The `del` function is used to delete the content of a node if needed.
/// @param lst the address of a pointer to a node.
/// @param f the address of the function used to iterate on the list.
/// @param del the address of a the function used to delete 
/// the content of a node if needed.
/// @return the new list. NULL if the allocatioin fails.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*cur;
	t_list	*tmp;

	if (!lst || !f)
		return (0);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (0);
	cur = new;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		cur->next = tmp;
		cur = tmp;
		lst = lst->next;
	}
	return (new);
}
