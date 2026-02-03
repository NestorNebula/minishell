/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:04:54 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/03 12:14:56 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env.h"
#include "libft.h"

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

void		free_env_var(void *env_var)
{
	if (env_var == NULL)
		return ;
	free(((t_env_var *) env_var)->value);
	free((void *)((t_env_var *) env_var)->key);
	free((t_env_var *) env_var);
}
