/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:29:25 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/15 14:38:21 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "command.h"
#include "file.h"
#include "libft.h"

static t_command	*set_command_default_files(t_command *command);

t_command	*new_command(const char **raw_argv)
{
	t_command	*command;

	command = malloc(sizeof(t_command));
	if (command == NULL)
		return (NULL);
	command->raw_argv = raw_argv;
	command->args = NULL;
	command->filepath = NULL;
	command->pid = -1;
	command->wstatus = -1;
	if (set_command_default_files(command) == NULL)
	{
		free_command(command);
		return (NULL);
	}
	return (command);
}

void	free_command(void *command)
{
	ft_free_arr(((t_command *) command)->args, free);
	if (((t_command *) command)->filepath != NULL)
		free(((t_command *) command)->filepath);
	clear_dll(&((t_command *) command)->in_files, free_file);
	clear_dll(&((t_command *) command)->out_files, free_file);
	free(command);
}

static t_command	*set_command_default_files(t_command *command)
{
	t_dll		**node_ptr;
	t_file		*file;

	command->in_files = NULL;
	command->out_files = NULL;
	node_ptr = &command->in_files;
	while (node_ptr != NULL)
	{
		file = new_file(NULL, FILE_STD, 0);
		if (file == NULL)
			return (NULL);
		add_dll(node_ptr, new_dll(file));
		if (*node_ptr == NULL)
		{
			free_file(file);
			return (NULL);
		}
		if (*node_ptr == command->in_files)
			node_ptr = &command->out_files;
		else
			node_ptr = NULL;
	}
	return (command);
}
