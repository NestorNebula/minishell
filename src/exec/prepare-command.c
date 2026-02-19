/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare-command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:59:03 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/06 12:18:11 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include "exec.h"
#include "file.h"

static int	prepare_stds(t_command *command, t_command *prev);

int	prepare_command(t_dll *command_node)
{
	int			rc;
	t_command	*command;
	t_command	*prev;

	if (command_node == NULL || command_node->data == NULL)
		return (0);
	command = command_node->data;
	if (command_node->prev == NULL)
		prev = NULL;
	else
		prev = command_node->prev->data;
	if (rc != 0)
		return (rc);
	rc = prepare_stds(command, prev);
	return (rc);
}

static int	prepare_stds(t_command *command, t_command *prev)
{
	int		rc;
	t_file	*last_in;
	t_file	*last_out;

	rc = 0;
	last_in = NULL;
	if (command->in_files != NULL)
		last_in = dll_last(command->in_files)->data;
	last_out = NULL;
	if (command->out_files != NULL)
		last_out = dll_last(command->out_files)->data;
	if (last_in != NULL && last_in->type == FILE_PIPE
		&& prev != NULL && dup2(prev->pipe[0], STDIN_FILENO) == -1)
		rc = errno;
	else if (last_in != NULL && dup2(last_in->fd, STDIN_FILENO) == -1)
		rc = errno;
	if (last_out == NULL || last_out->type != FILE_PIPE)
		close(command->pipe[1]);
	if (last_out != NULL && last_out->type == FILE_PIPE
		&& dup2(command->pipe[1], STDOUT_FILENO) == -1)
		rc = errno;
	else if (last_out != NULL && dup2(last_out->fd, STDIN_FILENO) == -1)
		rc = errno;
	return (rc);
}
