/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:31:51 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/02 18:31:52 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fd.h"

t_fd		*new_fd(int fd, int status)
{
	t_fd	*fd_ptr;

	fd_ptr = malloc(sizeof(t_fd));
	if (fd_ptr == NULL)
		return (NULL);
	fd_ptr->fd = fd;
	fd_ptr->status = status;
	return (fd_ptr);
}

void		free_fd(void *fd)
{
	free(fd);
}
