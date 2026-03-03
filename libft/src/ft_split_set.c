/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 08:45:54 by nhoussie          #+#    #+#             */
/*   Updated: 2026/03/01 09:24:51 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "libft.h"

static void	free_strs(char **strs, size_t size);

static int	handle_strs(const char *s, const char *set, char **split);

static char	*dup_until(const char *s, const char *set);

static bool	is_delimiter(char c, const char *set);

/**
 *  Allocates memory (using malloc(3)) and returns an array of strings
 *  obtained by splitting 's' using a set of characters as delimiters.
 *  The array must end with a NULL pointer.
 *
 *  @param s The string to be split
 *  @param set An array of characters considered as delimiters
 *  @return The array of new strings resulting from the split.
 *  NULL if the allocation fails
 */
char	**ft_split_set(char const *s, const char *set)
{
	char	**split;
	int		strs_count;

	if (s == NULL)
		return (NULL);
	strs_count = handle_strs(s, set, NULL);
	split = malloc(sizeof(char *) * (strs_count + 1));
	if (split == NULL)
		return (NULL);
	if (handle_strs(s, set, split) == -1)
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

static int	handle_strs(const char *s, const char *set, char **split)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && is_delimiter(*s, set))
			s++;
		if (*s != '\0')
		{
			if (split != NULL)
			{
				split[count] = dup_until(s, set);
				if (split[count] == NULL)
				{
					free_strs(split, count);
					return (-1);
				}
			}
			count++;
		}	
		while (*s != '\0' && !is_delimiter(*s, set))
			s++;
	}
	return (count);
}

static char	*dup_until(const char *s, const char *set)
{
	char	*dup;
	size_t	i;

	i = 0;
	while (s[i] != '\0' && !is_delimiter(s[i], set))
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && !is_delimiter(s[i], set))
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static bool	is_delimiter(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0' && set[i] != c)
		i++;
	return (c == set[i]);
}
