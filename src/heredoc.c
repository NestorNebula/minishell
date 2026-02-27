/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:29:57 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/27 10:06:34 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"
#include "expansion.h"
#include "get_next_line.h"
#include "libft.h"
#include "shell_signal.h"
#include "heredoc.h"

#define SIGRC 128

extern volatile sig_atomic_t	g_signal;

static int	handle_heredoc(const char *delimiter, t_pipe hd_pipe,
				t_shell *shell);

static int	read_heredoc(const char *delimiter, const char *unquoted_delimiter,
				int fd, t_shell *shell);

static int	reset_stdin(int stdin_dup_fd, t_file *hd_file);

int	get_heredoc(const char *delimiter, t_file *hd_file, t_shell *shell)
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
	hd_file->err_code = handle_heredoc(delimiter, hd_pipe, shell);
	if (reset_stdin(stdin_dup_fd, hd_file) != -1)
		hd_file->fd = hd_pipe[0];
	else
		close(hd_pipe[0]);
	set_default_signals();
	return (hd_file->fd);
}

static int	handle_heredoc(const char *delimiter, t_pipe hd_pipe,
				t_shell *shell)
{
	int		rc;
	char	*unquoted_delimiter;

	hd_pipe[1] = -1;
	hd_pipe[0] = -1;
	unquoted_delimiter = remove_quotes((char *) delimiter);
	if (unquoted_delimiter == NULL)
		return (errno);
	if (open_heredoc(hd_pipe) == -1)
	{
		rc = errno;
		free(unquoted_delimiter);
		return (rc);
	}
	rc = read_heredoc(delimiter, unquoted_delimiter, hd_pipe[1], shell);
	if (rc == -1)
		rc = errno;
	free(unquoted_delimiter);
	close(hd_pipe[1]);
	if (rc != 0)
		close(hd_pipe[0]);
	return (rc);
}

static int	read_heredoc(const char *delimiter, const char *unquoted_delimiter,
				int fd, t_shell *shell)
{
	char	*line;
	size_t	delimiter_len;
	int		rc;

	delimiter_len = ft_strlen(unquoted_delimiter);
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		write(STDOUT_FILENO, "> ", 2);
	line = get_next_line(STDIN_FILENO);
	rc = 0;
	while (line != NULL
		&& (ft_strncmp(line, unquoted_delimiter, delimiter_len) != 0
			|| line[delimiter_len] != '\n'))
	{
		rc = handle_line(line, delimiter, fd, shell);
		free(line);
		if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
			write(STDOUT_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	get_next_line(-1);
	return (rc);
}

static int	reset_stdin(int stdin_dup_fd, t_file *hd_file)
{
	int	rc;

	rc = 0;
	if (dup2(stdin_dup_fd, STDIN_FILENO) == -1)
	{
		hd_file->err_code = errno;
		rc = -1;
	}
	else if (g_signal == SIGINT)
	{
		hd_file->err_code = SIGRC + SIGINT;
		rc = -1;
	}
	close(stdin_dup_fd);
	return (rc);
}
