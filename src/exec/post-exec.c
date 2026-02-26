/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post-exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:43:33 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/05 18:43:51 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "exec.h"
#include "file.h"

static void	close_inputs(t_dll *command_node);

static void	close_outputs(t_dll	*command_node);

void	close_files(t_dll *command_node)
{
	if (command_node == NULL || command_node->data == NULL)
		return ;
	close_inputs(command_node);
	close_outputs(command_node);
}

static void	close_inputs(t_dll *command_node)
{
	t_command	*command;
	t_command	*prev;
	t_dll		*file_node;
	t_file		*file;

	command = command_node->data;
	file_node = command->in_files;
	while (file_node != NULL && file_node->data != NULL)
	{
		file = file_node->data;
		if (file->status == FILE_OK
			&& (file->type == FILE_REG || file->type == FILE_HEREDOC))
			close(file->fd);
		file_node = file_node->next;
	}
	if (command_node->prev != NULL)
	{
		prev = command_node->prev->data;
		close(prev->pipe[0]);
	}
}

static void	close_outputs(t_dll	*command_node)
{
	t_command	*command;
	t_dll		*file_node;
	t_file		*file;

	command = command_node->data;
	close(command->pipe[1]);
	file_node = command->out_files;
	while (file_node != NULL && file_node->data != NULL)
	{
		file = file_node->data;
		if (file->status == FILE_OK && file->type == FILE_REG)
			close(file->fd);
		file_node = file_node->next;
	}
	if (command_node->next == NULL)
		close(command->pipe[0]);
}
