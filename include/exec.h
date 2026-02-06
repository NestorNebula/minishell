/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:09:25 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/06 10:23:03 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "command.h"

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
 * Executes the given command.
 *
 * @param command A pointer to a command structure
 * @return Doesn't return on success, the code of the error that occurred
 * otherwise
 */
int		exec_command(t_command *command);

/**
 * Closes all input/output files used by the given command.
 *
 * @param command A pointer to a command structure
 */
void	close_files(t_command *command);

#endif // !EXEC_H
