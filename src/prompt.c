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
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

char	*get_prompt(void)
{
	char	*line;
	char	*newline;

	newline = NULL;
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		line = readline("minishell$ ");
	else
	{
		line = get_next_line(STDIN_FILENO);
		if (line != NULL)
			newline = ft_strchr(line, '\n');
		if (newline != NULL)
			*newline = '\0';
	}
	if (!line)
		return (NULL);
	if (*line)
		add_history(line);
	return (line);
}
