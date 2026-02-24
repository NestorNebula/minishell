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

#include "dll.h"
#include "env.h"
#include "libft.h"

static	t_env_var	*create_env_var(char *str)
{
	char	*equal;
	char	*key;
	char	*value;

	equal = ft_strchr(str, '=');
	if (!equal)
		return (NULL);
	key = ft_substr(str, 0, equal - str);
	value = ft_strdup(equal + 1);
	if (!key || !value)
		return (NULL);
	return (new_env_var(key, value));
}

t_dll	*envp_to_env(char **envp)
{
	t_dll		*env;
	t_dll		*node;
	t_env_var	*var;
	int			i;

	env = NULL;
	i = 0;
	while (envp[i])
	{
		var = create_env_var(envp[i]);
		if (!var)
			return (NULL);
		node = new_dll(var);
		if (!node)
			return (NULL);
		add_dll(&env, node);
		i++;
	}
	return (env);
}
