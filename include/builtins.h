/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:34:01 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/17 11:10:56 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "command.h"
# include "shell.h"

typedef int	(*t_builtin_fn)(t_command *, t_shell *);

typedef struct s_builtin
{
	const char		*name;
	t_builtin_fn	ptr;
}	t_builtin;

/**
 * Searches for a builtin command.
 *
 * @param name A command's name
 * @return A pointer to a builtin command's function if found,
 * a NULL pointer otherwise
 */
t_builtin_fn	get_builtin(const char *name);

/**
 * Echoes the command's arguments.
 *
 * @param command A pointer to a command structure
 * @param shell A pointer to a shell structure
 * @return 0 on success, > 0 on error
 */
int				builtin_echo(t_command *command, t_shell *shell);

/**
 * Changes the working directory of the current shell execution environment.
 *
 * @param command A pointer to a command structure
 * @param shell A pointer to a shell structure
 * @return 0 on success, > 0 on error
 */
int				builtin_cd(t_command *command, t_shell *shell);

/**
 * Prints the name of the current working directory.
 *
 * @param command A pointer to a command structure
 * @param shell A pointer to a shell structure
 * @return 0 on success, > 0 on error
 */
int				builtin_pwd(t_command *command, t_shell *shell);

/**
 * Adds every argument variable stored in the command's arguments to
 * the shell's environment variables.
 *
 * @param command A pointer to a command structure
 * @param shell A pointer to a shell structure
 * @return 0 on success, > 0 on error
 */
int				builtin_export(t_command *command, t_shell *shell);

/**
 * Removes every argument variable stored in the command's arguments from
 * the shell's environment variables.
 *
 * @param command A pointer to a command structure
 * @param shell A pointer to a shell structure
 * @return 0 on success, > 0 on error
 */
int				builtin_unset(t_command *command, t_shell *shell);

/**
 * Prints the shell's environment variables.
 *
 * @param command A pointer to a command structure
 * @param shell A pointer to a shell structure
 * @return 0 on success, > 0 on error
 */
int				builtin_env(t_command *command, t_shell *shell);

/**
 * Exits the current shell execution environment with the exit value of
 * the last command executed.
 *
 * @param command A pointer to a command structure
 * @param shell A pointer to a shell structure
 * @return The exit value of the last executed command
 */
int				builtin_exit(t_command *command, t_shell *shell);

#endif // !BUILTINS_H
