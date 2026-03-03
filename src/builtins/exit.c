/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:56:01 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/18 15:11:21 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include "builtins.h"
#include "libft.h"

static bool	arg_is_int(const char *arg);

static bool	int_from_arg(const char *arg, int *int_ptr);

int	builtin_exit(t_command *command, t_shell *shell)
{
	int	rc;

	if (command->args[1] == NULL)
	{
		shell->running = false;
		return (shell->last_status);
	}
	if (!arg_is_int(command->args[1]) || !int_from_arg(command->args[1], &rc))
	{
		ft_dprintf(STDERR_FILENO, "exit: %s: numeric argument required\n",
			command->args[1]);
		shell->running = false;
		return (2);
	}
	if (command->args[2] != NULL)
	{
		ft_dprintf(STDERR_FILENO, "exit: too many arguments\n");
		return (1);
	}
	shell->running = false;
	return ((unsigned char) rc);
}

static bool	arg_is_int(const char *arg)
{
	while (*arg == ' ')
		arg++;
	if (*arg == '+' || *arg == '-')
		arg++;
	if (!ft_isdigit(*arg))
		return (false);
	while (ft_isdigit(*arg))
		arg++;
	while (*arg == ' ')
		arg++;
	return (*arg == '\0');
}

static bool	int_from_arg(const char *arg, int *int_ptr)
{
	uint64_t	nbr;
	int			tmp;
	bool		is_negative;

	nbr = 0;
	is_negative = *arg == '-';
	if (*arg == '-' || *arg == '+')
		arg++;
	while (ft_isdigit(*arg))
	{
		nbr = nbr * 10 + (*arg - '0');
		if ((!is_negative && nbr > INT_MAX)
			|| (is_negative && nbr > (unsigned int) INT_MAX + 1))
			return (false);
		arg++;
	}
	tmp = nbr;
	if (is_negative)
		tmp = -((int) nbr);
	if (int_ptr != NULL)
		*int_ptr = tmp;
	return (true);
}
