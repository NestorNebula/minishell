/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:13:55 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/17 11:38:23 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "builtins.h"
#include "libft.h"

static int	echo(char **args, char *option);

int	builtin_echo(t_command *command, t_shell *shell)
{
	int		rc;
	char	*option;

	option = NULL;
	if (command->args != NULL && command->args[1] != NULL
		&& ft_strncmp(command->args[1], "-n", 2) == 0
		&& ft_strchr(command->args[1], ' ') == NULL)
		option = command->args[1];
	return (echo(command->args + 1, option));
}

static int	echo(char **args, char *option)
{
	int		rc;
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (args[i] != NULL)
	{
		if (args[i] != option && ft_strlen(args[i]) > 0)
		{
			if (count++ > 0)
				rc = ft_printf(" %s", args[i]);
			else
				rc = ft_printf("%s", args[i]);
		}
		i++;
	}
	if (rc == -1)
		return (errno);
	return (0);
}
