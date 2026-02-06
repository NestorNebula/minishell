/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:09:25 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/06 14:19:36 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "command.h"
# include "shell.h"

/**
 * Prepares input/output files needed by the given command.
 * Stops at the first encountered error.
 *
 * @param command A pointer to a command structure
 * @return 0 on success, the error code of the
 * first encountered error otherwise
 */
int		prepare_files(t_command *command);

/**
 * Prepares the given command for execution.
 *
 * @param command_node A pointer to a dll node containing a command structure
 * @return 0 on success, an error code otherwise
 */
int		prepare_command(t_dll *command_node);

/**
 * Creates a process to execute the given command in the given shell.
 *
 * @param command A pointer to a command structure
 * @param shell A pointer to a shell structure
 * @return 0 if the process was created successfully, an error code otherwise
 */
int		handle_command(t_command *command, t_shell *shell);

/**
 * Executes the given command.
 *
 * @param command A pointer to a command structure
 * @param shell A pointer to a shell structure
 * @return Doesn't return on success, the code of the error that occurred
 * otherwise
 */
int		exec_command(t_command *command, t_shell *shell);

/**
 * Closes all input/output files used by the given command.
 *
 * @param command A pointer to a command structure
 */
void	close_files(t_command *command);

#endif // !EXEC_H
