/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:53:28 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/06 15:07:02 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "process.h"

static size_t	get_commands_count(t_dll *commands);

static void		set_command_wstatus(t_dll *commands, int command_pid,
					int wstatus);

void	wait_pids(t_dll *commands)
{
	size_t		count;
	size_t		i;
	int			wstatus;
	int			pid;

	count = get_commands_count(commands);
	i = 0;
	while (i < count)
	{
		pid = waitpid(-1, &wstatus, P_ALL);
		if (pid > 0)
			set_command_wstatus(commands, pid, wstatus);
		i++;
	}
}

static size_t	get_commands_count(t_dll *commands)
{
	size_t		count;
	t_command	*command;

	count = 0;
	while (commands != NULL)
	{
		command = commands->data;
		if (command != NULL && command->pid != -1)
			count++;
		commands = commands->next;
	}
	return (count);
}

static void		set_command_wstatus(t_dll *commands, int command_pid,
					int wstatus)
{
	t_command	*command;

	while (commands != NULL)
	{
		command = commands->data;
		if (command != NULL && command->pid == command_pid)
		{
			command->wstatus = wstatus;
			commands = NULL;
		}
		else
			commands = commands->next;
	}
}
