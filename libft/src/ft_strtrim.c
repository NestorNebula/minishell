/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:05:50 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/14 08:40:33 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 *  Allocates memory (using malloc(3)) and returns a copy of 's1'
 *  with characters from 'set' removed from the beginning and the end.
 *
 *  @param s1 The string to be trimmed
 *  @param set The string containing the set of characters to be removed
 *  @return The trimmed string. NULL if the allocation fails
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trimmed;
	const char	*start;
	const char	*end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = s1;
	while (*start != '\0' && ft_strchr(set, *start) != NULL)
		start++;
	end = s1 + ft_strlen(s1) - 1;
	while (start < end && ft_strchr(set, *end) != NULL)
		end--;
	if (start[0] == '\0' && start >= end)
		return (ft_strdup(""));
	trimmed = malloc(sizeof(char) * (end - start + 2));
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, start, end - start + 2);
	return (trimmed);
}
