/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle-command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:37:45 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/19 15:39:36 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include "builtins.h"
#include "exec.h"
#include "process.h"

static int	handle_builtin(t_command *command, t_shell *shell);

int	handle_command(t_dll *command_node, t_shell *shell)
{
	int			rc;
	t_command	*command;

	if (command_node == NULL || command_node->data == NULL)
		return (0);
	command = command_node->data;
	if (pipe(command->pipe) == -1)
		return (errno);
	rc = prepare_files(command);
	if (rc != 0)
		return (rc);
	rc = handle_builtin(command, shell);
	if (rc != -1)
		return (rc);
	rc = fork();
	if (rc == 0)
		handle_child(command_node, shell);
	else if (rc > 0)
		rc = handle_parent(command, rc);
	else
		rc = errno;
	close_files(command);
	return (rc);
}

static int	handle_builtin(t_command *command, t_shell *shell)
{
	int				rc;
	t_builtin_fn	builtin;
	
	if (dll_size(shell->cmds) != 1 || command->args == NULL)
		return (-1);
	builtin = get_builtin(command->args[0]);
	if (builtin == NULL)
		return (-1);
	rc = builtin(command, shell);
	command->wstatus = rc << 8;
	return (rc);
}
