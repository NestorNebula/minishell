/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:15:14 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/18 13:43:25 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdbool.h>
#include <unistd.h>
#include "builtins.h"
#include "env.h"
#include "libft.h"

static bool	is_valid_key(const char *key);

static int	export_env_var(t_shell *shell, char *env_str);

int	builtin_export(t_command *command, t_shell *shell)
{
	int		rc;
	bool	error;
	size_t	i;

	error = false;
	i = 1;
	while (command->args[i] != NULL)
	{
		if (!is_valid_key(command->args[i]))
		{
			error = true;
			ft_dprintf(STDERR_FILENO, "export: %s: not a valid identifier\n",
				command->args[i]);
		}
		else if (ft_strchr(command->args[i], '=') != NULL)
			rc = export_env_var(shell, command->args[i]);
		i++;
	}
	if (error)
		return (1);
	return (rc);
}

static bool	is_valid_key(const char *key)
{
	bool	success;
	size_t	i;

	if (key == NULL || (!ft_isalpha(key[0]) && key[0] != '_'))
		return (false);
	success = true;
	i = 1;
	while (key[i] != '\0' && key[i] != '=' && success)
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			success = false;
		i++;
	}
	return (success);
}

static int	export_env_var(t_shell *shell, char *env_str)
{
	size_t	key_len;
	void	*rp;

	key_len = ft_strchr(env_str, '=') - env_str;
	env_str[key_len] = '\0';
	rp = set_env_var(&shell->env, env_str, env_str + key_len + 1);
	env_str[key_len] = '=';
	if (rp == NULL)
		return (errno);
	return (0);
}
