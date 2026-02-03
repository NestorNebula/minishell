/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filepath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 08:31:13 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/03 08:59:35 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include "filepath.h"
#include "libft.h"

#define PATHS_KEY "PATH"

static char	*get_next_path(const char **paths_ptr, char *buf);

static char	*try_path(const char *filename, const char *path);

char	*find_filepath(const char *filename)
{
	const char	*paths;
	char		path[PATH_MAX + 2];
	char		*filepath;
	
	if (filename == NULL || ft_strchr("./", filename[0]))
		return (NULL);
	paths = getenv(PATHS_KEY);
	if (paths == NULL)
		return (NULL);
	filepath = NULL;
	while (filepath == NULL && get_next_path(&paths, path) != NULL)
		filepath = try_path(filename, path);
	return (filepath);
}

static char	*get_next_path(const char **paths_ptr, char *buf)
{
	size_t		size;
	char		*next_delimiter;

	if (paths_ptr == NULL || *paths_ptr == NULL)
		return (NULL);
	while (**paths_ptr == ':')
		(*paths_ptr)++;
	next_delimiter = ft_strchr(*paths_ptr, ':');
	if (next_delimiter == NULL)
		return (NULL);
	size = next_delimiter - *paths_ptr;
	if (size == 0)
		return (NULL);
	ft_strlcpy(buf, *paths_ptr, size + 1);
	buf[size] = '/';
	buf[size + 1] = '\0';
	*paths_ptr += size + 1;
	return (buf);
}

static char	*try_path(const char *filename, const char *path)
{
	char	*filepath;
	size_t	size;

	size = ft_strlen(filename) + ft_strlen(path) + 1;
	filepath = malloc(sizeof(char) * (size));
	if (filepath == NULL)
		return (NULL);
	ft_strlcpy(filepath, path, size);
	ft_strlcat(filepath, filename, size);
	if (access(filepath, F_OK) == 0)
		return (filepath);
	free(filepath);
	return (NULL);
}
