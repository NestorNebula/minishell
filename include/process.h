/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:06:08 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/06 10:23:01 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "command.h"
# include "shell.h"

/**
 * Executes the given command inside a child process using the
 * environment variables provided by the given shell.
 *
 * @param command A pointer to a command structure
 * @param shell A pointer to a shell structure
 * @return Doesn't return on success, the code of the error that occurred
 * otherwise
 */
int		handle_child(t_command *command, t_shell *shell);

/**
 * Updates the given command with the process id of the child
 * that is currently executing
 *
 * @param command A pointer to a command structure
 * @param pid The process id of the child currently executing
 */
void	handle_parent(t_command *command, int pid);

/**
 * Waits for every child process currently executing to terminate.
 *
 * @param commands A pointer to a dll of commands
 */
void	wait_pids(t_dll *commands);

#endif // !PROCESS_H
