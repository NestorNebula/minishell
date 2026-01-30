/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:19:05 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/10 13:10:09 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem;
	size_t			i;

	mem = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (mem[i] == (unsigned char) c)
			return (mem + i);
		i++;
	}
	return (NULL);
}
