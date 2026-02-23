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

#include "heredoc.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"
#include "get_next_line.h"
#include "libft.h"

static int	open_hd_file(t_pipe hd_pipe);

static int	read_heredoc(const char *delimiter, int fd);

int	get_heredoc(const char *delimiter)
{
	t_pipe	hd_pipe;
	int		rc;

	if (delimiter == NULL)
		return (-1);
	hd_pipe[1] = -1;
	hd_pipe[0] = -1;
	if (open_hd_file(hd_pipe) == -1)
	{
		close(hd_pipe[1]);
		if (pipe(hd_pipe) == -1)
			return (-1);
	}
	rc = read_heredoc(delimiter, hd_pipe[1]);
	close(hd_pipe[1]);
	if (rc == -1)
	{
		close(hd_pipe[0]);
		return (rc);
	}
	return (hd_pipe[0]);
}

static int	open_hd_file(t_pipe hd_pipe)
{
	char	*path;
	char	*fd_str;

	hd_pipe[1] = open("/tmp", O_TMPFILE | O_WRONLY, 0644);
	if (hd_pipe[1] == -1)
		return (-1);
	fd_str = ft_itoa(hd_pipe[1]);
	if (fd_str == NULL)
		return (-1);
	path = ft_strjoin("/proc/self/fd/", fd_str);
	free(fd_str);
	if (path == NULL)
		return (-1);
	hd_pipe[0] = open(path, O_RDONLY);
	free(path);
	if (hd_pipe[0] == -1)
		return (-1);
	return (0);
}

static int	read_heredoc(const char *delimiter, int fd)
{
	char	*line;
	size_t	delimiter_len;
	int		rc;

	delimiter_len = ft_strlen(delimiter);
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "> ", 2);
	line = get_next_line(STDIN_FILENO);
	rc = 0;
	while (line != NULL
		&& (ft_strncmp(line, delimiter, delimiter_len) != 0
			|| line[delimiter_len] != '\n'))
	{
		if (ft_dprintf(fd, "%s", line) == -1)
			rc = -1;
		free(line);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	get_next_line(-1);
	return (rc);
}
