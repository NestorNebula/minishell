/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_commands_files.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:15:34 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/15 11:17:34 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "build_commands.h"
#include "command.h"
#include "expansion.h"
#include "file.h"

static int	update_command_files(t_command *command, t_dll *command_node,
				size_t in_size, size_t out_size);

static int	update_files_path(t_dll *files, t_shell *shell);

int	update_commands_files(t_dll *commands, t_shell *shell)
{
	t_command	*command;

	while (commands != NULL)
	{
		command = commands->data;
		if ((dll_size(command->in_files) > 0
				&& update_files_path(command->in_files, shell) == -1)
			|| (dll_size(command->out_files) > 0
				&& update_files_path(command->out_files, shell) == -1))
			return (-1);
		update_command_files(command, commands,
			dll_size(command->in_files), dll_size(command->out_files));
		commands = commands->next;
	}
	return (0);
}

static int	update_command_files(t_command *command, t_dll *command_node,
				size_t in_size, size_t out_size)
{
	t_dll	*next;

	if (in_size > 1 && ((t_file *) command->in_files->data)->type == FILE_STD)
	{
		next = command->in_files->next;
		free_dll(command->in_files, free_file);
		command->in_files = next;
	}
	else if (in_size == 1 && command_node->prev != NULL)
		((t_file *) command->in_files->data)->type = FILE_PIPE;
	if (out_size > 1 && ((t_file *) command->out_files->data)->type == FILE_STD)
	{
		next = command->out_files->next;
		free_dll(command->out_files, free_file);
		command->out_files = next;
	}
	else if (out_size == 1 && command_node->next != NULL)
		((t_file *) command->out_files->data)->type = FILE_PIPE;
	return (0);
}

static int	update_files_path(t_dll *files, t_shell *shell)
{
	t_file	*file;
	char	*expanded;
	char	*unquoted;

	while (files != NULL)
	{
		file = files->data;
		if (file->path != NULL)
		{
			expanded = expand_string((char *) file->path, shell);
			if (expanded == NULL)
				return (-1);
			unquoted = remove_quotes(expanded);
			free(expanded);
			if (unquoted == NULL)
				return (-1);
			free((char *) file->path);
			file->path = unquoted;
		}
		files = files->next;
	}
	return (0);
}
