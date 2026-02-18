/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 08:09:28 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/18 08:57:26 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "builtins.h"
#include "env.h"

static int	cd(const char *path);

static void	update_pwd(t_shell *shell, const char *pwd);

int				builtin_cd(t_command *command, t_shell *shell)
{
	int		rc;

	rc = cd(command->args[1]);
	update_pwd(shell, command->args[1]);
	return (rc);
}

static int	cd(const char *path)
{
	return (chdir(path));
}

static void	update_pwd(t_shell *shell, const char *pwd)
{
	t_env_var	*old_pwd;

	old_pwd = find_env_var(shell->env, "PWD");
	if (old_pwd != NULL)
		set_env_var(&shell->env, "OLDPWD", old_pwd->value);
	if (pwd != NULL)
		set_env_var(&shell->env, "PWD", (char *) pwd);
}
