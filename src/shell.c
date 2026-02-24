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

#include <stdlib.h>
#include "env.h"
#include "prompt.h"
#include "shell.h"

void	init_shell(t_shell *shell, char **envp)
{
	shell->env = env_from_envp(envp);
	shell->cmds = NULL;
	shell->last_status = 0;
	shell->running = 1;
}

void	shell_loop(t_shell *shell)
{
	char	*line;

	while (shell->running)
	{
		line = get_prompt();
		if (!line)
		{
			shell->running = 0;
			break ;
		}
		// parse_and_execute(shell, line);
		free(line);
	}
}
