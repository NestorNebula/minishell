/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:10:36 by cmonmire          #+#    #+#             */
/*   Updated: 2026/02/23 22:18:37 by cmonmire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env.h"
#include "libft.h"

static char	*build_env_line(t_env_var *var)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin(var->key, "=");
	if (!tmp)
		return (NULL);
	result = ft_strjoin(tmp, var->value);
	free(tmp);
	return (result);
}

char	**env_to_envp(t_dll *env)
{
	char		**envp;
	t_dll		*tmp;
	t_env_var	*var;
	int			size;
	int			i;

	size = dll_size(env);
	envp = malloc(sizeof(char *) * (size + 1));
	if (!envp)
		return (NULL);
	i = 0;
	tmp = env;
	while (tmp)
	{
		var = (t_env_var *)tmp->data;
		envp[i] = build_env_line(var);
		if (envp[i] == NULL)
			break ;
		tmp = tmp->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}
