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
#include <string.h>
#include <unistd.h>
#include "builtins.h"
#include "exec.h"
#include "env.h"
#include "libft.h"
#include "process.h"

static void	exit_from_child(int ec, t_dll *command_node, t_shell *shell);

static void	display_exec_error(t_command *command, int *ec);

int	handle_child(t_dll *command_node, t_shell *shell)
{
	int			ec;
	t_command	*command;

	if (command_node == NULL || command_node->data == NULL || shell == NULL)
		exit_from_child(0, command_node, shell);
	command = command_node->data;
	close(command->pipe[0]);
	ec = prepare_command(command_node, shell);
	close_files(command_node);
	if (ec != 0)
		exit_from_child(ec, NULL, shell);
	ec = exec_command(command, shell);
	display_exec_error(command, &ec);
	exit_from_child(ec, NULL, shell);
	exit(ec);
}

static void	exit_from_child(int ec, t_dll *command_node, t_shell *shell)
{
	if (command_node != NULL)
		close_files(command_node);
	if (shell != NULL)
	{
		clear_dll(&shell->cmds, free_command);
		clear_dll(&shell->env, free_env_var);
	}
	exit(ec);
}

static void	display_exec_error(t_command *command, int *ec)
{
	const char	*command_name;

	if (*ec == 0)
		return ;
	command_name = command->filepath;
	if (command_name == NULL)
		command_name = command->args[0];
	if (command_name == NULL || get_builtin(command_name) != NULL)
		return ;
	if (*ec == 127
		|| (*ec == 2 && command_name[0] != '/' && command_name[0] != '.'))
		ft_dprintf(STDERR_FILENO, "%s: command not found\n", command_name);
	else if (*ec == 2)
		ft_dprintf(STDERR_FILENO, "%s: %s\n", command_name, strerror(*ec));
	else if (access(command_name, R_OK) < 0 || access(command_name, X_OK) < 0)
	{
		ft_dprintf(STDERR_FILENO, "%s: %s\n", command_name, strerror(*ec));
		*ec = 126;
	}
	else
		ft_dprintf(STDERR_FILENO, "%s: %s\n", command_name, strerror(*ec));
	if (*ec == 2)
		*ec = 127;
}
