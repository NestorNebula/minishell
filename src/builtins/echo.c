/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:13:55 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/19 15:53:57 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "builtins.h"
#include "libft.h"

#define OPT_LEN 2

static bool	has_option(const char *arg);

static int	echo(char **args, bool n_option);

int	builtin_echo(t_command *command, t_shell *shell)
{
	size_t	options_count;

	(void) shell;
	options_count = 0;
	while (has_option(command->args[options_count + 1]))
		options_count++;
	return (echo(command->args + options_count + 1, options_count != 0));
}

static bool	has_option(const char *arg)
{
	bool	success;
	size_t	i;

	if (arg == NULL || ft_strncmp(arg, "-n", OPT_LEN) != 0)
		return (false);
	i = OPT_LEN;
	success = true;
	while (arg[i] != '\0' && success)
		if (arg[i++] != 'n')
			success = false;
	return (success);
}

static int	echo(char **args, bool n_option)
{
	int		rc;
	size_t	i;
	size_t	count;

	rc = 0;
	count = 0;
	i = 0;
	while (args[i] != NULL)
	{
		if (ft_strlen(args[i]) > 0)
		{
			if (count++ > 0)
				rc = printf(" %s", args[i]);
			else
				rc = printf("%s", args[i]);
		}
		i++;
	}
	if (rc == -1)
		rc = errno;
	else
		rc = 0;
	if (!n_option)
		printf("\n");
	return (rc);
}
