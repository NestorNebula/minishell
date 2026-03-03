/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:11:39 by cmonmire          #+#    #+#             */
/*   Updated: 2026/02/24 16:16:37 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "dll.h"

typedef struct s_shell
{
	t_dll	*env;
	t_dll	*cmds;
	int		last_status;
	int		running;
}	t_shell;

#endif
