/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:11:20 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/24 10:15:54 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec(t_dll *commands, t_shell *shell)
{
	int	rc;

	rc = exec_line(commands, shell);
	rc = end_exec(commands, shell, rc);
	return (rc);
}
