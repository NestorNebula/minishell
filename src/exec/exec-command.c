/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec-command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:15:48 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/19 14:57:56 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtins.h"
#include "env.h"
#include "libft.h"

int	exec_command(t_command *command, t_shell *shell)
{
	t_builtin_fn	builtin;
	char			**envp;

	if (command == NULL || command->args == NULL
		|| command->args[0] == NULL)
		return (0);
	builtin = get_builtin(command->args[0]);
	if (builtin != NULL)
		return (builtin(command, shell));
	envp = env_to_envp(shell->env);
	if (command->filepath != NULL)
		execve(command->filepath, command->args, envp);
	else if (ft_strchr("./", command->args[0][0]) != NULL)
		execve(command->args[0], command->args, envp);
	else
	{
		ft_free_arr(envp, free);
		return (127);
	}
	ft_free_arr(envp, free);
	return (errno);
}
