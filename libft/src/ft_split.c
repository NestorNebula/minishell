/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 10:06:29 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/12 17:08:04 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	free_strs(char **strs, size_t size);

static int	handle_strs(const char *s, char c, char **split);

static char	*dup_until(const char *s, char c);

/**
 *  Allocates memory (using malloc(3)) and returns an array of strings
 *  obtained by splitting 's' using the character 'c' as a delimiter.
 *  The array must end with a NULL pointer.
 *
 *  @param s The string to be split
 *  @param c The delimiter character
 *  @return The array of new strings resulting from the split.
 *  NULL if the allocation fails
 */
char	**ft_split(char const *s, char c)
{
	char	**split;
	int		strs_count;

	if (s == NULL)
		return (NULL);
	strs_count = handle_strs(s, c, NULL);
	split = malloc(sizeof(char *) * (strs_count + 1));
	if (split == NULL)
		return (NULL);
	if (handle_strs(s, c, split) == -1)
		return (NULL);
	split[strs_count] = NULL;
	return (split);
}

static void	free_strs(char **strs, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(strs[i++]);
	free(strs);
}

static int	handle_strs(const char *s, char c, char **split)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			if (split != NULL)
			{
				split[count] = dup_until(s, c);
				if (split[count] == NULL)
				{
					free_strs(split, count);
					return (-1);
				}
			}
			count++;
		}	
		while (*s != '\0' && *s != c)
			s++;
	}
	return (count);
}

static char	*dup_until(const char *s, char c)
{
	char	*dup;
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
