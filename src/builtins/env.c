/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:37:55 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/18 14:46:47 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "builtins.h"
#include "libft.h"
#include "env.h"

int	builtin_env(t_command *command, t_shell *shell)
{
	int			rc;
	t_dll		*env_ptr;
	t_env_var	*env_var;

	(void) command;
	rc = 0;
	env_ptr = shell->env;
	while (env_ptr != NULL)
	{
		env_var = env_ptr->data;
		if (env_var != NULL)
			rc = ft_printf("%s=%s\n", env_var->key, env_var->value);
		env_ptr = env_ptr->next;
	}
	if (rc == -1)
		return (errno);
	return (0);
}
