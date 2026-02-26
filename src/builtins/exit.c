/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:56:01 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/18 15:11:21 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "builtins.h"

int	builtin_exit(t_command *command, t_shell *shell)
{
	(void) command;
	shell->running = false;
	return (shell->last_status);
}
