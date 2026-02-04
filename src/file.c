/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:31:51 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/04 10:18:33 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "file.h"
#include "libft.h"

t_file	*new_file(const char *path, int fd, t_file_status status)
{
	t_file	*file;

	if (path == NULL)
		return (NULL);
	file = malloc(sizeof(t_file));
	if (file == NULL)
		return (NULL);
	file->path = ft_strdup(path);
	if (file->path == NULL)
	{
		free(file);
		return (NULL);
	}
	file->fd = fd;
	file->status = status;
	return (file);
}

void		free_file(void *file)
{
	if (file != NULL)
	{
		free((void *)((t_file *) file)->path);
		free(file);
	}
}
