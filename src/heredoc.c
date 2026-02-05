/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:29:57 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/05 08:50:54 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "command.h"
#include "get_next_line.h"
#include "heredoc.h"
#include "libft.h"

static int	read_heredoc(const char *delimiter, int fd);

int	get_heredoc(const char *delimiter)
{
	t_pipe	hd_pipe;
	int		rc;
	
	if (delimiter == NULL)
		return (-1);
	if (pipe(hd_pipe) == -1)
		return (-1);
	rc = read_heredoc(delimiter, hd_pipe[1]);
	close(hd_pipe[1]);
	if (rc == -1)
	{
		close(hd_pipe[0]);
		return (rc);
	}
	return (hd_pipe[0]);
}

static int	read_heredoc(const char *delimiter, int fd)
{
	char	*line;
	size_t	delimiter_len;
	int		rc;

	delimiter_len = ft_strlen(delimiter);
	write(STDOUT_FILENO, "> ", 2);
	line = get_next_line(STDIN_FILENO);
	rc = 0;
	while (line != NULL && ft_strncmp(line, delimiter, delimiter_len + 1) != 0)
	{
		if (ft_dprintf(fd, "%s", line) == -1)
			rc = -1;
		free(line);
		write(STDOUT_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	get_next_line(-1);
	return (rc);
}
