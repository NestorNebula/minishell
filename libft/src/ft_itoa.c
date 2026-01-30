/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:06:21 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/08 12:51:56 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	handle_nbr(int nbr, char *str);

/**
 *	Allocates memory (using malloc(3)) and returns a string representing
 *	the integer received as an argument.
 *
 *	@param n The integer to convert
 *	@return The string representing the integer. NULL if the allocation fails
 */
char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	size = handle_nbr(n, NULL) + 1;
	str = malloc(sizeof(char) * (size));
	if (str == NULL)
		return (NULL);
	handle_nbr(n, str + (size - 2));
	str[size - 1] = '\0';
	return (str);
}

static size_t	handle_nbr(int nbr, char *end_str)
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
	while (n / 10 > 0)
	{
		size++;
		if (end_str != NULL)
			*end_str-- = '0' + (n % 10);
		n /= 10;
	}
	if (end_str != NULL)
		*end_str-- = '0' + (n % 10);
	if (is_negative && end_str != NULL)
		*end_str = '-';
	return (size);
}
