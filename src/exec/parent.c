/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:45:09 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/06 14:47:15 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "process.h"

void	handle_parent(t_command *command, int pid)
{
	if (command != NULL)
	{
		close(command->pipe[1]);
		command->pid = pid;
	}
}
