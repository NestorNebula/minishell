/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:04:54 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/03 13:02:14 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env.h"
#include "libft.h"

static	t_env_var	*add_env_var(t_dll **env_vars_ptr, const char *key,
						char *value);

t_env_var	*new_env_var(const char *key, char *value)
{
	t_env_var	*env_var;

	if (key == NULL || value == NULL)
		return (NULL);
	env_var = malloc(sizeof(t_env_var));
	if (env_var == NULL)
		return (NULL);
	env_var->key = ft_strdup(key);
	env_var->value = ft_strdup(value);
	if (env_var->key == NULL || env_var->value == NULL)
	{
		free((void *) env_var->key);
		free(env_var->value);
		free(env_var);
		return (NULL);
	}
	return (env_var);
}

t_env_var	*find_env_var(t_dll *env_vars, const char *key)
{
	t_env_var	*env_var;

	if (key == NULL)
		return (NULL);
	env_var = NULL;
	while (env_var == NULL && env_vars != NULL)
	{
		env_var = env_vars->data;
		if (ft_strncmp(env_var->key, key, ft_strlen(key) + 1) != 0)
			env_var = NULL;
		env_vars = env_vars->next;
	}
	return (env_var);
}

t_env_var	*set_env_var(t_dll **env_vars_ptr, const char *key, char *value)
{
	char		*new_value;
	t_env_var	*env_var;

	if (env_vars_ptr == NULL || key == NULL || value == NULL)
		return (NULL);
	env_var = find_env_var(*env_vars_ptr, key);
	if (env_var == NULL)
		env_var = add_env_var(env_vars_ptr, key, value);
	else
	{
		new_value = ft_strdup(value);
		if (new_value == NULL)
			return (NULL);
		free(env_var->value);
		env_var->value = new_value;
	}
	return (env_var);
}

void	free_env_var(void *env_var)
{
	if (env_var == NULL)
		return ;
	free(((t_env_var *) env_var)->value);
	free((void *)((t_env_var *) env_var)->key);
	free((t_env_var *) env_var);
}

static	t_env_var	*add_env_var(t_dll **env_vars_ptr, const char *key,
						char *value)
{
	t_dll		*node;
	t_env_var	*env_var;

	if (env_vars_ptr == NULL || key == NULL || value == NULL)
		return (NULL);
	env_var = new_env_var(key, value);
	if (env_var == NULL)
		return (NULL);
	node = new_dll(env_var);
	if (node == NULL)
	{
		free_env_var(env_var);
		return (NULL);
	}
	add_dll(env_vars_ptr, node);
	return (env_var);
}
