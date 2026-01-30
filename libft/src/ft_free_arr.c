/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:43:17 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/30 11:47:56 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_free_arr(void *arr, void (*free_item)(void *))
{
	void	**tmp;

	if (arr != NULL)
	{
		if (free_item != NULL)
		{
			tmp = (void **) arr;
			while (tmp != NULL)
				(*free_item)(*tmp++);
		}
		free(arr);
	}
}
