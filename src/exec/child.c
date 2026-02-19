/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:20:55 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/06 14:48:48 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "exec.h"
#include "env.h"
#include "file.h"
#include "process.h"

static void	exit_from_child(int ec, t_dll *command_node, t_shell *shell);

static void	close_fds(t_dll *command_node);

int	handle_child(t_dll *command_node, t_shell *shell)
{
	int			ec;
	t_command	*command;

	if (command_node == NULL || command_node->data == NULL || shell == NULL)
		exit_from_child(0, command_node, shell);
	command = command_node->data;
	close(command->pipe[0]);
	ec = prepare_command(command_node);
	if (ec != 0)
		exit_from_child(ec, command_node, shell);
	ec = exec_command(command, shell);
	exit_from_child(ec, command_node, shell);
	exit(ec);
}

static void	exit_from_child(int ec, t_dll *command_node, t_shell *shell)
{
	if (command_node != NULL)
		close_fds(command_node);
	if (shell != NULL)
	{
		clear_dll(&shell->cmds, free_command);
		clear_dll(&shell->env, free_env_var);
	}
	exit(ec);
}

static void	close_fds(t_dll *command_node)
{
	t_command	*command;
	t_command	*prev;
	t_file		*last_in;
	t_file		*last_out;

	command = command_node->data;
	prev = NULL;
	if (command_node->prev != NULL && command_node->prev->data != NULL)
		prev = command_node->prev->data;
	last_in = NULL;
	if (command->in_files != NULL)
		last_in = dll_last(command->in_files)->data;
	last_out = NULL;
	if (command->out_files != NULL)
		last_out = dll_last(command->out_files)->data;
	if (last_in != NULL && last_in->type == FILE_PIPE && prev != NULL)
		close(prev->pipe[0]);
	else if (last_in != NULL && last_in->type)
		close(last_in->fd);
	if (last_out != NULL && last_out->type == FILE_PIPE)
		close(command->pipe[1]);
	else if (last_out != NULL)
		close(last_out->fd);
}
