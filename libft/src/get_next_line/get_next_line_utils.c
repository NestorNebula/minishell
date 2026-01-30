/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:03:43 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/27 09:26:11 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

t_gnl_list	*gnl_lst_new(int fd)
{
	t_gnl_list	*new;

	new = (t_gnl_list *) malloc(sizeof(t_gnl_list));
	if (new == NULL)
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	new->cont.fd = fd;
	new->cont.buf[0] = '\0';
	new->cont.buf_len = 0;
	new->cont.line = NULL;
	new->cont.line_len = 0;
	new->cont.line_size = 0;
	return (new);
}

void	gnl_lst_add(t_gnl_list **lst, t_gnl_list *new)
{
	t_gnl_list	*last;

	if (lst == NULL)
		return ;
	if (*lst != NULL)
	{
		last = *lst;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
	else
		*lst = new;
}

void	gnl_lst_free(t_gnl_list *lst, bool free_all)
{
	t_gnl_list	*next;

	if (free_all)
	{
		while (lst != NULL)
		{
			next = lst->next;
			free(lst);
			lst = next;
		}
	}
	else if (lst != NULL)
	{
		if (lst->prev != NULL)
			lst->prev->next = lst->next;
		if (lst->next != NULL)
			lst->next->prev = lst->prev;
		free(lst);
	}
}

t_gnl_list	*gnl_lst_find(t_gnl_list *lst, int fd)
{
	t_gnl_list	*node;

	node = lst;
	while (node != NULL && node->cont.fd != fd)
		node = node->next;
	return (node);
}

size_t	ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (i);
}
