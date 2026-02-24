/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:11:43 by cmonmire          #+#    #+#             */
/*   Updated: 2026/02/24 16:16:51 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/history.h>
#include <readline/readline.h>

char	*get_prompt(void)
{
	char	*line;

	line = readline("minishell$ ");
	if (!line)
		return (NULL);
	if (*line)
		add_history(line);
	return (line);
}
