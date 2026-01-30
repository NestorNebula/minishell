/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus.ft_lstdelone.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:11:43 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/10 17:15:58 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 *  Takes a node as a parameter and frees its content using the function 'del'.
 *  Free the node itself but does NOT free the next node.
 *
 *  @param lst The node to free
 *  @param del The address of the function use to delete the content
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		if (del != NULL)
			del(lst->content);
		free(lst);
	}
}
