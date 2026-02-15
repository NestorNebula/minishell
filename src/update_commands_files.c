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

#include "build_commands.h"
#include "command.h"
#include "file.h"

static void	update_command_files(t_command *command, t_dll *command_node,
				size_t in_size, size_t out_size);

void	update_commands_files(t_dll *commands)
{
	t_command	*command;

	while (commands != NULL)
	{
		command = commands->data;
		update_command_files(command, commands,
			dll_size(command->in_files), dll_size(command->out_files));
		commands = commands->next;
	}
}

static void	update_command_files(t_command *command, t_dll *command_node,
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
}
