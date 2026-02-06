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
#include "process.h"

static void	exit_from_child(int ec, t_shell *shell);

int		handle_child(t_dll *command_node, t_shell *shell)
{
	int			ec;
	t_command	*command;

	if (command_node == NULL || command_node->data == NULL || shell == NULL)
		exit_from_child(0, shell);
	command = command_node->data;
	close(command->pipe[0]);
	ec = prepare_command(command_node);
	if (ec != 0)
		exit_from_child(ec, shell);
	ec = exec_command(command, shell);
	exit_from_child(ec, shell);
	exit(ec);
}

static void	exit_from_child(int ec, t_shell *shell)
{
	if (shell != NULL)
	{
		clear_dll(&shell->cmds, free_command);
		clear_dll(&shell->env, free_env_var);
	}
	exit(ec);
}
