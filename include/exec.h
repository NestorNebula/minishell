/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:09:25 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/23 08:08:22 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "command.h"
# include "shell.h"

/**
 * Prompts for the content of every heredoc needed by the given commands.
 *
 * @param commands A pointer the first node of a dll structure
 * @return 0 on success, the error code of the 
 * first encountered error otherwise
 */
int		prepare_heredocs(t_dll *commands);

/**
 * Prepares input/output files needed by the given command.
 * Stops at the first encountered error.
 *
 * @param command_node A pointer to a dll node containing
 * a pointer to a command structure
 * @return 0 on success, the error code of the
 * first encountered error otherwise
 */
int		prepare_files(t_dll *command_node);

/**
 * Prepares the given command for execution.
 *
 * @param command_node A pointer to a dll node containing
 * a pointer to a command structure
 * @return 0 on success, an error code otherwise
 */
int		prepare_command(t_dll *command_node);

/**
 * Creates a process to execute the given command in the given shell.
 *
 * @param command_node A pointer to a dll node containing
 * a pointer to a command structure
 * @param shell A pointer to a shell structure
 * @return 0 if the process was created successfully, an error code otherwise
 */
int		handle_command(t_dll *command_node, t_shell *shell);

/**
 * Executes every command in the given list of commands.
 *
 * @param commands A pointer to the first node of a dll structure
 * @param shell A pointer to a shell structure
 * @return 0 if the last command was executed successfully,
 * > 0 if an error occurred for the last command
 */
int		exec_line(t_dll *commands, t_shell *shell);

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
 * Waits for every executed command to end and computes
 * the return code for the given list of commands.
 *
 * @param commands A pointer to the first node of a dll structure
 * @param shell A pointer to a shell structure
 * @return The return code for the last command of the given command list
 */
int		end_exec(t_dll *commands, t_shell *shell);

/**
 * Closes all input/output files used by the given command.
 *
 * @param command_node A pointer to a dll node containing
 * a pointer to a command structure
 */
void	close_files(t_dll *command_node);

#endif // !EXEC_H
