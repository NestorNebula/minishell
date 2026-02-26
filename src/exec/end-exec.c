/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end-exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 07:59:30 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/23 08:50:28 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "builtins.h"
#include "exec.h"
#include "process.h"

#define SIGDEF 128

int	end_exec(t_dll *commands, t_shell *shell, int exec_rc)
{
	t_command	*last_command;

	(void) shell;
	if (commands == NULL)
		return (exec_rc);
	wait_pids(commands);
	last_command = dll_last(commands)->data;
	if (last_command->args == NULL || last_command->args[0] == NULL)
		return (exec_rc);
	if (get_builtin(last_command->args[0]) != NULL
		&& commands->data == last_command)
		return (exec_rc);
	if (WIFSIGNALED(last_command->wstatus))
		return (SIGDEF + WTERMSIG(last_command->wstatus));
	if (WIFEXITED(last_command->wstatus))
		return (WEXITSTATUS(last_command->wstatus));
	if (last_command->wstatus == -1)
		return (exec_rc);
	return (last_command->wstatus);
}
