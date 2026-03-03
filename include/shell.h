/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:11:39 by cmonmire          #+#    #+#             */
/*   Updated: 2026/02/24 16:16:37 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "dll.h"

typedef struct s_shell
{
	t_dll	*env;
	t_dll	*cmds;
	int		last_status;
	int		running;
}	t_shell;

/**
 * Initializes the given shell structure.
 *
 * @param shell A pointer to a shell structure
 * @param envp A pointer to the first element of an array of
 * environment variables
 */
void	init_shell(t_shell *shell, char **envp);

/**
 * Prompts for commands while the given shell is running.
 *
 * @param shell A pointer to a shell structure
 */
void	shell_loop(t_shell *shell);

#endif // !SHELL_H
