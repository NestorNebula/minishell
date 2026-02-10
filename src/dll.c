/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:26:04 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/03 10:46:14 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dll.h"

t_dll	*new_dll(void *data)
{
	t_dll	*dll;

	dll = malloc(sizeof(t_dll));
	if (dll == NULL)
		return (NULL);
	dll->prev = NULL;
	dll->next = NULL;
	dll->data = data;
	return (dll);
}

void	add_dll(t_dll **dll_ptr, t_dll *new_dll)
{
	t_dll	*last_node;

	if (dll_ptr == NULL)
		return ;
	if (*dll_ptr == NULL)
		*dll_ptr = new_dll;
	else
	{
		last_node = dll_last(*dll_ptr);
		last_node->next = new_dll;
		if (new_dll != NULL)
			new_dll->prev = last_node;
	}
}

void	free_dll(t_dll *dll, void (*del)(void *))
{
	if (dll == NULL)
		return ;
	if (del != NULL)
		del(dll->data);
	if (dll->prev != NULL)
		dll->prev->next = dll->next;
	if (dll->next != NULL)
		dll->next->prev = dll->prev;
	free(dll);
}

void	clear_dll(t_dll **dll, void (*del)(void *))
{
	t_dll	*next;

	if (dll == NULL)
		return ;
	while (*dll != NULL)
	{
		next = (*dll)->next;
		free_dll(*dll, del);
		*dll = next;
	}
}
