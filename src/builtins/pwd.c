/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 08:59:12 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/18 09:05:40 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "builtins.h"
#include "file.h"
#include "libft.h"

int	builtin_pwd(t_command *command, t_shell *shell)
{
	int		rc;
	int		fd;
	char	*cwd;

	(void) command;
	(void) shell;
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		return (errno);
	fd = STDOUT_FILENO;
	if (dll_size(shell->cmds) == 1)
		fd = ((t_file *) dll_last(command->out_files)->data)->fd;
	rc = ft_dprintf(fd, "%s\n", cwd);
	if (rc == -1)
	{
		rc = errno;
		ft_dprintf(STDERR_FILENO, "pwd: %s\n", strerror(rc));
	}
	else
		rc = 0;
	free(cwd);
	return (rc);
}
