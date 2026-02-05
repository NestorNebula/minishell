/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:25:59 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/04 14:16:24 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "dll.h"

typedef int	t_pipe[2];

typedef struct s_command {
	const char			**raw_argv;
	char				**args;
	char				*filepath;
	int					pid;
	int					wstatus;
	t_dll				*in_files;
	t_dll				*out_files;
	t_pipe				pipe;
}				t_command;

/**
 * Initializes a new command structure.
 *
 * @param raw_argv The initial args that will be used to create the command
 * @return A pointer to a command structure on success, NULL on error
 */
t_command	*new_command(const char **raw_argv);

/**
 * Frees a command structure.
 *
 * @param command A pointer to a command structure
 */
void		free_command(void *command);

#endif // !COMMAND_H
