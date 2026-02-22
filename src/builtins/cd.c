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

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "builtins.h"
#include "env.h"
#include "libft.h"

static int	cd(const char *path);

static void	update_pwd(t_shell *shell, const char *oldpwd, const char *pwd);

int	builtin_cd(t_command *command, t_shell *shell)
{
	int		rc;
	char	*old_cwd;
	char	*cwd;

	if (command->args[1] == NULL)
		return (0);
	old_cwd = getcwd(NULL, 0);
	rc = cd(command->args[1]);
	cwd = getcwd(NULL, 0);
	if (rc == 0)
		update_pwd(shell, old_cwd, cwd);
	free(old_cwd);
	free(cwd);
	return (rc);
}

static int	cd(const char *path)
{
	int	rc;

	rc = chdir(path);
	if (rc == 0)
		return (rc);
	rc = errno;
	ft_dprintf(STDERR_FILENO, "cd: %s: %s\n", path, strerror(rc));
	return (rc);
}

static void	update_pwd(t_shell *shell, const char *oldpwd, const char *pwd)
{
	if (oldpwd != NULL)
		set_env_var(&shell->env, "OLDPWD", (char *) oldpwd);
	if (pwd != NULL)
		set_env_var(&shell->env, "PWD", (char *) pwd);
}
