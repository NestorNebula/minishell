/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:29:20 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/25 09:21:24 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	handle_unbr(unsigned int u, const char *base,
					size_t base_len, char *end_str);

/**
 *  Allocates memory (using malloc(3)) and returns a string representing
 *  the unsigned integer received as an argument in the provided base.
 *
 *  @param n The unsigned integer to convert
 *  @param base The base used to convert the unsigned integer 
 *  @return The string representing the unsigned integer.
 *  NULL If the allocations fails
 */
char	*ft_uitoa_base(unsigned int n, const char *base)
{
	char	*str;
	size_t	size;
	size_t	base_len;

	base_len = ft_strlen(base);
	size = handle_unbr(n, base, base_len, NULL) + 1;
	str = malloc(sizeof(char) * (size));
	if (str == NULL)
		return (NULL);
	handle_unbr(n, base, base_len, str + (size - 2));
	str[size - 1] = '\0';
	return (str);
}

static size_t	handle_unbr(unsigned int u, const char *base,
		size_t base_len, char *end_str)
{
	size_t			size;

	size = 1;
	while (u / base_len > 0)
	{
		size++;
		if (end_str != NULL)
			*end_str-- = base[u % base_len];
		u /= base_len;
	}
	if (end_str != NULL)
		*end_str-- = base[u % base_len];
	return (size);
}
