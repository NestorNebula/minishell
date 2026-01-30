/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus.ft_lstiter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:53:50 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/10 17:20:43 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  Iterates trough the list 'lst' and applies the function 'f'
 *  to the content of each node.
 *
 *  @param lst The address of a pointer to a node
 *  @param f The address of the function to apply to each node's content
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		if (f != NULL)
			(*f)(lst->content);
		lst = lst->next;
	}
}
