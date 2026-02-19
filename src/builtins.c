/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:53:51 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/17 11:10:33 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "libft.h"

#define BUILTINS_COUNT 7

t_builtin_fn	get_builtin(const char *name)
{
	static const t_builtin	builtins[BUILTINS_COUNT] = {
	{"echo", builtin_echo},
	{"cd", builtin_cd},
	{"pwd", builtin_pwd},
	{"export", builtin_export},
	{"unset", builtin_unset},
	{"env", builtin_env},
	{"exit", builtin_exit},
	};
	size_t					i;

	i = 0;
	while (i < BUILTINS_COUNT
		&& ft_strncmp(builtins[i].name, name, ft_strlen(name) + 1) != 0)
		i++;
	if (i == BUILTINS_COUNT)
		return (NULL);
	return (builtins[i].ptr);
}
