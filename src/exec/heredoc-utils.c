/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc-utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 08:44:10 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/27 10:05:40 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "expansion.h"
#include "libft.h"

int	open_heredoc(t_pipe hd_pipe)
{
	char	*path;
	char	*fd_str;

	hd_pipe[1] = open("/tmp", O_TMPFILE | O_WRONLY, 0644);
	if (hd_pipe[1] == -1)
		return (-1);
	fd_str = ft_itoa(hd_pipe[1]);
	if (fd_str == NULL && ft_close(hd_pipe[1]) >= -1)
		return (-1);
	path = ft_strjoin("/proc/self/fd/", fd_str);
	free(fd_str);
	if (path == NULL && ft_close(hd_pipe[1]) >= -1)
		return (-1);
	hd_pipe[0] = open(path, O_RDONLY);
	free(path);
	if (hd_pipe[0] == -1)
	{
		ft_close(hd_pipe[1]);
		if (pipe(hd_pipe) == -1)
			return (-1);
	}
	return (0);
}

int	handle_line(char *line, const char *delimiter, int fd, t_shell *shell)
{
	int		rc;
	size_t	delimiter_len;
	bool	expand;
	char	*expanded;

	delimiter_len = ft_strlen(delimiter);
	expand = !(delimiter[0] == delimiter[delimiter_len - 1]
			&& (delimiter[0] == '\"' || delimiter[0] == '\''));
	if (!expand)
	{
		rc = ft_dprintf(fd, "%s", line);
		if (rc == -1)
			return (errno);
		return (0);
	}
	expanded = expand_string(line, shell);
	if (expanded == NULL)
		return (errno);
	rc = ft_dprintf(fd, "%s", expanded);
	free(expanded);
	if (rc == -1)
		return (errno);
	return (0);
}
