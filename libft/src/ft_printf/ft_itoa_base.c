/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:23:27 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/25 09:20:38 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	handle_nbr(int nbr, const char *base,
					size_t base_len, char *end_str);

/**
 *  Allocates memory (using malloc(3)) and returns a string representing
 *  the integer received as an argument in the provided base.
 *
 *  @param n The integer to convert
 *  @param base The base used to convert the integer 
 *  @return The string representing the integer. NULL If the allocations fails
 */
char	*ft_itoa_base(int n, const char *base)
{
	char	*str;
	size_t	size;
	size_t	base_len;

	base_len = ft_strlen(base);
	size = handle_nbr(n, base, base_len, NULL) + 1;
	str = malloc(sizeof(char) * (size));
	if (str == NULL)
		return (NULL);
	handle_nbr(n, base, base_len, str + (size - 2));
	str[size - 1] = '\0';
	return (str);
}

static size_t	handle_nbr(int nbr, const char *base,
		size_t base_len, char *end_str)
{
	size_t			size;
	unsigned int	n;
	int				is_negative;

	size = 1;
	is_negative = nbr < 0;
	if (is_negative)
	{
		size++;
		n = -nbr;
	}
	else
		n = nbr;
	while (n / base_len > 0)
	{
		size++;
		if (end_str != NULL)
			*end_str-- = base[n % base_len];
		n /= base_len;
	}
	if (end_str != NULL)
		*end_str-- = base[n % base_len];
	if (is_negative && end_str != NULL)
		*end_str = '-';
	return (size);
}
