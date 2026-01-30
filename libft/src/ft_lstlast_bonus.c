/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus.ft_lstlast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:41:25 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/10 17:10:28 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *	Returns the last node of the list
 *
 *	@param lst The beginning of the list
 *	@return Last node of the list
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*next;

	if (lst == NULL)
		return (NULL);
	next = lst->next;
	while (next != NULL)
	{
		lst = next;
		next = lst->next;
	}
	return (lst);
}
