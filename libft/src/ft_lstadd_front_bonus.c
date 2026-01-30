/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus.ft_lstadd_front.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:04:07 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/10 17:06:46 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  Adds the node 'new' at the beginning of the list
 *
 *  @param lst The address of a pointer to the first node of a list
 *  @param new The address of a pointer to the node to be added
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
