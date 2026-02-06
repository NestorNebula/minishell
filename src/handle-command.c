/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle-command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:37:45 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/06 14:37:58 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include "exec.h"
#include "process.h"

int		handle_command(t_dll *command_node, t_shell *shell)
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
	rc = fork();
	if (rc == 0)
		handle_child(command_node, shell);
	else if (rc > 0)
	{
		handle_parent(command, rc);
		rc = 0;
	}
	else
		rc = errno;
	close_files(command);
	return (rc);
}
