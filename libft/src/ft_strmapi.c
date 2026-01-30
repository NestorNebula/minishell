/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:19:54 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/12 16:18:17 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 *  Applies the function f to each character of the string s,
 *  passing its index as the first argument and
 *  the character itself as the second.
 *  A new string is created (using malloc(3)) to store
 *  the results from the successive applications of f.
 *
 *  @param s The string to iterate over
 *  @param f The function to apply to each character
 *  @return The string created from the successive applications of 'f'.
 *  Returns NULL if the allocation fails
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
