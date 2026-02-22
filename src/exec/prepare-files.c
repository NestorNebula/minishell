/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare-files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:59:42 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/06 11:00:50 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include "exec.h"
#include "file.h"
#include "heredoc.h"

static int	prepare_inputs(t_dll *command_node, t_dll *inputs);

static int	prepare_outputs(t_dll *command_node, t_dll *outputs);

int		prepare_files(t_dll *command_node)
{
	int			rc;
	t_command	*command;

	if (command_node == NULL || command_node->data == NULL)
		return (0);
	command = command_node->data;
	rc = 0;
	if (command->in_files != NULL)
		rc = prepare_inputs(command_node, command->in_files);
	if (rc != 0)
		return (rc);
	if (command->out_files != NULL)
		rc = prepare_outputs(command_node, command->out_files);
	return (rc);
}

static int	prepare_inputs(t_dll *command_node, t_dll *inputs)
{
	int		rc;
	t_file	*file;

	rc = 0;
	while (inputs != NULL && inputs->data != NULL && rc == 0)
	{
		file = inputs->data;
		if (file->type == FILE_HEREDOC)
			file->fd = get_heredoc(file->path);
		else if (file->type == FILE_REG)
			file->fd = open(file->path, file->flags);
		else if (file->type == FILE_STD)
			file->fd = STDIN_FILENO;
		else if (file->type == FILE_PIPE && command_node->prev != NULL)
			file->fd = ((t_command *) command_node->prev->data)->pipe[0];
		if (file->fd == -1)
			rc = errno;
		file->err_code = rc;
		if (file->err_code == 0)
			file->status = FILE_OK;
		else
			file->status = FILE_ERR;
		inputs = inputs->next;
	}
	return (rc);
}

static int	prepare_outputs(t_dll *command_node, t_dll *outputs)
{
	int		rc;
	t_file	*file;

	rc = 0;
	while (outputs != NULL && outputs->data != NULL && rc == 0)
	{
		file = outputs->data;
		if (file->type == FILE_REG)
			file->fd = open(file->path, file->flags, 0644);
		else if (file->type == FILE_STD)
			file->fd = STDOUT_FILENO;
		else if (file->type == FILE_PIPE)
			file->fd = ((t_command *) command_node->data)->pipe[1];
		if (file->fd == -1)
			rc = errno;
		file->err_code = rc;
		if (file->err_code == 0)
			file->status = FILE_OK;
		else
			file->status = FILE_ERR;
		outputs = outputs->next;
	}
	return (rc);
}
