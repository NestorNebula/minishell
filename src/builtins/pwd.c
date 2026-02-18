/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 08:59:12 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/18 09:05:40 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtins.h"
#include "libft.h"

int				builtin_pwd(t_command *command, t_shell *shell)
{
	int		rc;
	char	*cwd;

	(void) command;
	(void) shell;
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		return (errno);
	rc = ft_printf("%s\n", cwd);
	if (rc == -1)
		return (errno);
	free(cwd);
	return (0);
}
