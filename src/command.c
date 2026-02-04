/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:29:25 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/04 14:16:49 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "command.h"

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
	command->in_files = NULL;
	command->out_files = NULL;
	return (command);
}

void	free_command(void *command)
{
	free(command);
}
