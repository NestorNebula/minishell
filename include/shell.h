/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 01:42:44 by cmonmire          #+#    #+#             */
/*   Updated: 2026/02/05 01:46:39 by cmonmire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_shell
{
	t_dll   *env;
	t_cmd	*cmds;
	int		last_status;
	int		running;
}	t_shell;

#endif
