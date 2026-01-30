/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:52:07 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/14 08:41:49 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 *  Allocates memory (using malloc(3)) and returns a substring from
 *  the string 's'.
 *  The substring starts at index 'start' and has a maximum length of 'len'.
 *
 *  @param s The original string from which to create the substring
 *  @param start The starting index of the substring within 's'
 *  @param len The maximum length of the substring
 *  @return The substring. NULL if the allocation fails
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	substr_len;

	if (s == NULL || ft_strlen(s) < start)
		return (ft_strdup(""));
	substr_len = ft_strlen(s + start);
	if (substr_len > len)
		substr_len = len;
	substr = malloc(sizeof(char) * substr_len + 1);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, substr_len + 1);
	return (substr);
}
