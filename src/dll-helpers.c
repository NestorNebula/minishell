/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll-helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:45:40 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/03 10:46:18 by nhoussie         ###   ########.fr       */
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

void	dll_for_each(t_dll *dll, void (*f)(void *))
{
	while (dll != NULL)
	{
		(*f)(dll);
		dll = dll->next;
	}
}
