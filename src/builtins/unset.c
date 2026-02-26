/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:00:45 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/18 14:12:56 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "dll.h"
#include "env.h"

static void	unset_env_var(t_shell *shell, const char *key);

int	builtin_unset(t_command *command, t_shell *shell)
{
	size_t		i;

	i = 1;
	while (command->args[i] != NULL)
		unset_env_var(shell, command->args[i++]);
	return (0);
}

static void	unset_env_var(t_shell *shell, const char *key)
{
	t_dll		*env_vars;
	t_env_var	*env_var;

	env_var = find_env_var(shell->env, key);
	if (env_var == NULL)
		return ;
	env_vars = shell->env;
	while (env_vars != NULL && env_vars->data != env_var)
		env_vars = env_vars->next;
	if (env_vars != NULL)
		free_dll(env_vars, free_env_var);
}
