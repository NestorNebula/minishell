/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:29:57 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/26 14:31:46 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"
#include "get_next_line.h"
#include "libft.h"
#include "shell_signal.h"

#define SIGRC 128

extern volatile sig_atomic_t g_signal;

static int	open_hd_file(t_pipe hd_pipe);

static int	handle_heredoc(const char *delimiter, t_pipe hd_pipe);

static int	read_heredoc(const char *delimiter, int fd);

static int	reset(int stdin_dup_fd, int content_fd, t_file *hd_file);

int	get_heredoc(const char *delimiter, t_file *hd_file)
{
	t_pipe	hd_pipe;
	int		stdin_dup_fd;

	stdin_dup_fd = dup(STDIN_FILENO);
	if (stdin_dup_fd == -1)
	{
		hd_file->err_code = errno;
		return (-1);
	}
	set_heredoc_signals();
	hd_file->err_code = handle_heredoc(delimiter, hd_pipe);
	if (reset(stdin_dup_fd, hd_pipe[0], hd_file) != -1)
		hd_file->fd = hd_pipe[0];
	return (hd_file->fd);
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

static int	handle_heredoc(const char *delimiter, t_pipe hd_pipe)
{
	int	rc;

	hd_pipe[1] = -1;
	hd_pipe[0] = -1;
	if (open_hd_file(hd_pipe) == -1)
	{
		close(hd_pipe[1]);
		if (pipe(hd_pipe) == -1)
			return (errno);
	}
	rc = read_heredoc(delimiter, hd_pipe[1]);
	close(hd_pipe[1]);
	if (rc == -1)
	{
		rc = errno;
		close(hd_pipe[0]);
		return (rc);
	}
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
			rc = errno;
		free(line);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	get_next_line(-1);
	return (rc);
}

static int	reset(int stdin_dup_fd, int content_fd, t_file *hd_file)
{
	int	rc;

	rc = 0;
	if (dup2(stdin_dup_fd, STDIN_FILENO) == -1)
	{
		hd_file->err_code = errno;
		close(content_fd);
		rc = -1;
	}
	else if (g_signal == SIGINT)
	{
		hd_file->err_code = SIGRC + SIGINT;
		close(content_fd);
		rc = -1;
	}
	close(stdin_dup_fd);
	set_default_signals();
	return (rc);
}
