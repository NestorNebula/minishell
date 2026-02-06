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
#include "exec.h"
#include "file.h"
#include "heredoc.h"

static int	prepare_inputs(t_dll *inputs);

static int	prepare_outputs(t_dll *outputs);

int		prepare_files(t_command *command)
{
	int		rc;

	if (command == NULL)
		return (0);
	rc = 0;
	if (command->in_files != NULL)
		rc = prepare_inputs(command->in_files);
	if (rc != 0)
		return (rc);
	if (command->out_files != NULL)
		rc = prepare_outputs(command->out_files);
	return (rc);
}

static int	prepare_inputs(t_dll *inputs)
{
	int		rc;
	t_file	*file;

	rc = 0;
	while (inputs != NULL && inputs->data != NULL && rc == 0)
	{
		file = inputs->data;
		file->fd = 0;
		if (file->type == FILE_HEREDOC)
			file->fd = get_heredoc(file->path);
		else if (file->type == FILE_REG)
			file->fd = open(file->path, file->flags);
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



static int	prepare_outputs(t_dll *outputs)
{
	int		rc;
	t_file	*file;

	rc = 0;
	while (outputs != NULL && outputs->data != NULL && rc == 0)
	{
		file = outputs->data;
		file->fd = 0;
		if (file->type == FILE_REG)
			file->fd = open(file->path, file->flags, 0644);
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
