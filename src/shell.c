/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 06:57:04 by cmonmire          #+#    #+#             */
/*   Updated: 2026/02/21 06:58:56 by cmonmire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "env.h"
#include "exec.h"
#include "parser.h"
#include "prompt.h"
#include "shell.h"
#include "shell_signal.h"

#define SIGRC 128

extern volatile sig_atomic_t	g_signal;

void	init_shell(t_shell *shell, char **envp)
{
	shell->env = envp_to_env(envp);
	shell->cmds = NULL;
	shell->last_status = 0;
	shell->running = 1;
}

void	shell_loop(t_shell *shell)
{
	char	*line;

	while (shell->running)
	{
		g_signal = 0;
		set_default_signals();
		line = get_prompt();
		if (g_signal != 0)
			shell->last_status = SIGRC + g_signal;
		shell->cmds = parse(line, shell);
		if (shell->cmds != NULL)
		{
			set_exec_signals();
			shell->last_status = exec(shell->cmds, shell);
		}
		else if (line != NULL && line[0] != '\0')
			shell->last_status = 2;
		if (line == NULL)
			shell->running = 0;
		clear_dll(&shell->cmds, free_command);
		free(line);
	}
}
