/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll-helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:45:40 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/06 10:53:54 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

size_t	dll_size(t_dll *dll)
{
	size_t	count;

	if (dll == NULL)
		return (0);
	count = 0;
	while (dll != NULL)
	{
		count++;
		dll = dll->next;
	}
	return (count);
}

t_dll		*dll_last(t_dll *dll)
{
	if (dll == NULL)
		return (NULL);
	while (dll->next != NULL)
		dll = dll->next;
	return (dll);
}

void	dll_for_each(t_dll *dll, void (*f)(void *))
{
	while (dll != NULL)
	{
		(*f)(dll);
		dll = dll->next;
	}
}
