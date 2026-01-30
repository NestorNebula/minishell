/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus.ft_lstclear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:35:22 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/12 14:24:04 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  Deletes and frees the given node and all its successors,
 *  using the function 'del' and free(3).
 *  Finally, set the pointer to the list to NULL.
 *
 *  @param lst The address of a pointer to a node
 *  @param del The address of the function used to delete the content of the node
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}
