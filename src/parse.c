/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:29:55 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/27 15:46:01 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "build_commands.h"
#include "command.h"
#include "expansion.h"
#include "libft.h"
#include "parser.h"

static bool		check_tokens(t_dll *tokens);

static t_dll	*expand_commands(t_dll *commands, t_shell *shell);

t_dll	*parse(char *line, t_shell *shell)
{
	t_dll	*commands;
	t_dll	*tokens;

	if (line == NULL || shell == NULL)
		return (NULL);
	tokens = tokenizer(line);
	if (tokens == NULL)
		return (NULL);
	if (!check_tokens(tokens))
		return (NULL);
	commands = build_commands(tokens);
	clear_dll(&tokens, free_token);
	if (commands == NULL)
		return (NULL);
	if (expand_commands(commands, shell) == NULL)
	{
		clear_dll(&commands, free_command);
		return (NULL);
	}
	return (commands);
}

static bool	check_tokens(t_dll *tokens)
{
	t_parsing_table	parsing_table;
	t_token			*token;

	parsing_table = build_parsing_table();
	if (parsing_table == NULL)
	{
		clear_dll(&tokens, free_token);
		return (false);
	}
	token = parse_tokens(tokens, parsing_table);
	free(parsing_table);
	if (token != NULL)
	{
		ft_dprintf(STDERR_FILENO, "syntax error near token '%s'\n",
			token->value);
		clear_dll(&tokens, free_token);
		return (false);
	}
	return (true);
}

static t_dll	*expand_commands(t_dll *commands, t_shell *shell)
{
	t_dll		*command_node;
	t_command	*command;
	char		**expanded_args;

	command_node = commands;
	while (command_node != NULL)
	{
		command = command_node->data;
		if (command->args != NULL)
		{
			expanded_args = expand_args(command, shell);
			if (expanded_args == NULL)
				return (NULL);
			ft_free_arr(command->args, free);
			command->args = expanded_args;
		}
		command_node = command_node->next;
	}
	return (commands);
}
