/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare-files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:59:42 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/23 08:46:26 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "exec.h"
#include "file.h"
#include "heredoc.h"
#include "libft.h"

static int	prepare_inputs(t_dll *command_node, t_dll *inputs);

static int	prepare_outputs(t_dll *command_node, t_dll *outputs);

static int	handle_file_status(t_file *file);

int	prepare_heredocs(t_dll *commands)
{
	int			rc;
	t_command	*command;
	t_dll		*file_node;
	t_file		*file;

	rc = 0;
	while (commands != NULL && commands->data != NULL && rc == 0)
	{
		command = commands->data;
		file_node = command->in_files;
		while (file_node != NULL && file_node->data != NULL && rc == 0)
		{
			file = file_node->data;
			if (file->type == FILE_HEREDOC)
			{
				file->status = FILE_OK;
				if (get_heredoc(file->path, file) == -1)
					file->status = FILE_ERR;
				rc = file->err_code;
			}
			file_node = file_node->next;
		}
		commands = commands->next;
	}
	return (rc);
}

int	prepare_files(t_dll *command_node)
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
		if (file->type == FILE_REG)
			file->fd = open(file->path, file->flags);
		else if (file->type == FILE_STD)
			file->fd = STDIN_FILENO;
		else if (file->type == FILE_PIPE && command_node->prev != NULL)
			file->fd = ((t_command *) command_node->prev->data)->pipe[0];
		if (file->type != FILE_HEREDOC)
			rc = handle_file_status(file);
		else
			rc = file->err_code;
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
		rc = handle_file_status(file);
		outputs = outputs->next;
	}
	return (rc);
}

static int	handle_file_status(t_file *file)
{
	if (file->fd != -1)
	{
		file->err_code = 0;
		file->status = FILE_OK;
		return (0);
	}
	file->err_code = errno;
	file->status = FILE_ERR;
	if (file->type != FILE_HEREDOC)
		ft_dprintf(STDERR_FILENO, "%s: %s\n",
			file->path, strerror(file->err_code));
	return (file->err_code);
}
