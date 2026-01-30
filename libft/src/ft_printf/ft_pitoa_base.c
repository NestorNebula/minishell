/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:33:01 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/25 09:20:55 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "libft.h"

static size_t	handle_pnbr(uintptr_t p, const char *base,
					size_t base_len, char *end_str);

/**
 *  Allocates memory (using malloc(3)) and returns a string representing
 *  the value of the pointer's received as an argument in the provided base.
 *
 *  @param n The pointer to convert
 *  @param base The base used to convert the pointer 
 *  @return The string representing the pointer's value.
 *  NULL If the allocations fails
 */
char	*ft_pitoa_base(void *p, const char *base)
{
	char	*str;
	size_t	size;
	size_t	base_len;

	base_len = ft_strlen(base);
	size = handle_pnbr((uintptr_t) p, base, base_len, NULL) + 1;
	str = malloc(sizeof(char) * (size));
	if (str == NULL)
		return (NULL);
	handle_pnbr((uintptr_t) p, base, base_len, str + (size - 2));
	str[size - 1] = '\0';
	return (str);
}

static size_t	handle_pnbr(uintptr_t p, const char *base,
		size_t base_len, char *end_str)
{
	size_t			size;

	size = 1;
	while (p / base_len > 0)
	{
		size++;
		if (end_str != NULL)
			*end_str-- = base[p % base_len];
		p /= base_len;
	}
	if (end_str != NULL)
		*end_str-- = base[p % base_len];
	return (size);
}
