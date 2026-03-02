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

#include "exec.h"
#include "file.h"
#include "libft.h"

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
	t_file		*file;

	command = command_node->data;
	if (command->in_files != NULL)
	{
		file = dll_last(command->in_files)->data;
		if (file->status == FILE_OK
			&& (file->type == FILE_REG || file->type == FILE_HEREDOC))
			ft_close(file->fd);
	}
	if (command_node->prev != NULL)
	{
		prev = command_node->prev->data;
		ft_close(prev->pipe[0]);
	}
}

static void	close_outputs(t_dll	*command_node)
{
	t_command	*command;
	t_file		*file;

	command = command_node->data;
	ft_close(command->pipe[1]);
	if (command->out_files != NULL)
	{
		file = dll_last(command->out_files)->data;
		if (file->status == FILE_OK && file->type == FILE_REG)
			ft_close(file->fd);
	}
	if (command_node->next == NULL)
		ft_close(command->pipe[0]);
}
