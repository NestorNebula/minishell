/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec-line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 07:52:04 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/23 08:44:07 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_line(t_dll *commands, t_shell *shell)
{
	int	rc;

	(void) shell;
	rc = prepare_heredocs(commands);
	if (rc != 0)
		return (rc);
	while (commands != NULL)
	{
		rc = handle_command(commands, shell);
		commands = commands->next;
	}
	return (rc);
}
