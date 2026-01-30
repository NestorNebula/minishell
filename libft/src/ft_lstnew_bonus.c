/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus.ft_lstnew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:44:58 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/09 11:27:19 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 *	Allocates memory (using malloc(3)) and returns a new node.
 *	The 'content' member variable is initialized with
 *	the given parameter 'content'.
 *	The variable 'next' is initialized to NULL.
 *
 *	@param content The content to store in the new node
 *	@return A pointer to the new node
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
