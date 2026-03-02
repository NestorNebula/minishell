/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:09:04 by cmonmire          #+#    #+#             */
/*   Updated: 2026/02/23 22:10:07 by cmonmire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dll.h"
#include "env.h"
#include "libft.h"

static	t_env_var	*create_env_var(char *str)
{
	char		*equal;
	t_env_var	*env_var;

	equal = ft_strchr(str, '=');
	if (!equal)
		return (NULL);
	*equal = '\0';
	env_var = new_env_var(str, equal + 1);
	*equal = '=';
	return (env_var);
}

t_dll	*envp_to_env(char **envp)
{
	t_dll		*env;
	t_dll		*node;
	t_env_var	*var;
	int			i;

	env = NULL;
	i = 0;
	while (envp != NULL && envp[i])
	{
		var = create_env_var(envp[i++]);
		if (!var)
		{
			clear_dll(&env, free_env_var);
			return (NULL);
		}
		node = new_dll(var);
		if (!node)
		{
			free_env_var(var);
			clear_dll(&env, free_env_var);
			return (NULL);
		}
		add_dll(&env, node);
	}
	return (env);
}
