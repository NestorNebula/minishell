/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_commands.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 11:00:19 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/14 11:00:46 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_COMMANDS_H
# define BUILD_COMMANDS_H

# include "dll.h"

/**
 * Creates a list of commands from a list of tokens.
 * The function must be called with a valid list of tokens, otherwise
 * its behavior is undefined.
 *
 * @param tokens A pointer to the first element of a dll of tokens
 * @return A pointer to the first element of a dll of commands on success,
 * a NULL pointer on error
 */
t_dll	*build_commands(t_dll *tokens);

/**
 * Updates i/o files for each command in a command list.
 * Removes standard i/o from i/o list if there are other files in the list.
 * Replaces standard i/o by pipes if other commands are in the list.
 *
 * @param commands A pointer to the first element of a dll of commands
 */
void	update_commands_files(t_dll *commands);

#endif // !BUILD_COMMANDS_H
