/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 11:04:55 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/15 11:49:53 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "build_commands.h"
#include "command.h"
#include "file.h"
#include "libft.h"
#include "token.h"

static t_command	*build_command(t_dll **tokens_ptr);

static char			**set_command_args(t_command *command, t_dll **tokens_ptr);

static t_file		*set_command_file(t_command *command, t_dll **tokens_ptr);

static t_file		*get_command_file(t_dll **tokens_ptr);

t_dll	*build_commands(t_dll *tokens)
{
	t_dll		*commands;
	t_dll		*command_node;
	t_command	*command;

	commands = NULL;
	while (tokens != NULL && ((t_token *)tokens->data)->type != T_END)
	{
		command = build_command(&tokens);
		if (command == NULL)
		{
			clear_dll(&commands, free_command);
			return (NULL);
		}
		command_node = new_dll(command);
		if (command_node == NULL)
		{
			free_command(command);
			clear_dll(&commands, free_command);
			return (NULL);
		}
		add_dll(&commands, command_node);
	}
	update_commands_files(commands);
	return (commands);
}

static t_command	*build_command(t_dll **tokens_ptr)
{
	t_command	*command;
	t_token		*token;
	void		*ret_ptr;

	if (tokens_ptr == NULL || *tokens_ptr == NULL)
		return (NULL);
	command = new_command(NULL);
	if (command == NULL)
		return (NULL);
	if (((t_token *)(*tokens_ptr)->data)->type == T_PIPE)
		*tokens_ptr = (*tokens_ptr)->next;
	token = (*tokens_ptr)->data;
	while (token != NULL && token->type != T_END && token->type != T_PIPE)
	{
		if (token->type == T_WORD)
			ret_ptr = set_command_args(command, tokens_ptr);
		else
			ret_ptr = set_command_file(command, tokens_ptr);
		if (ret_ptr == NULL)
			return (NULL);
		token = NULL;
		if (*tokens_ptr != NULL)
			token = (*tokens_ptr)->data;
	}
	return (command);
}

static char	**set_command_args(t_command *command, t_dll **tokens_ptr)
{
	size_t	i;
	t_dll	*token;

	i = 0;
	token = *tokens_ptr;
	while (token != NULL && ((t_token *) token->data)->type == T_WORD)
	{
		i++;
		token = token->next;
	}
	command->args = malloc(sizeof(char *) * (i + 1));
	if (command->args == NULL)
		return (NULL);
	i = 0;
	while (*tokens_ptr != NULL
		&& ((t_token *)(*tokens_ptr)->data)->type == T_WORD)
	{
		command->args[i] = ft_strdup(((t_token *)(*tokens_ptr)->data)->value);
		if (command->args[i++] == NULL)
			return (NULL);
		*tokens_ptr = (*tokens_ptr)->next;
	}
	command->args[i] = NULL;
	return (command->args);
}

static t_file	*set_command_file(t_command *command, t_dll **tokens_ptr)
{
	t_dll		*file_node;
	t_file		*file;
	t_token		*token;

	file = get_command_file(tokens_ptr);
	if (file == NULL)
		return (NULL);
	file_node = new_dll(file);
	if (file_node == NULL)
	{
		free(file);
		return (NULL);
	}
	token = (*tokens_ptr)->data;
	if (token->type == T_REDIR_IN || token->type == T_HEREDOC)
		add_dll(&command->in_files, file_node);
	else
		add_dll(&command->out_files, file_node);
	*tokens_ptr = (*tokens_ptr)->next->next;
	return (file);
}

static t_file	*get_command_file(t_dll **tokens_ptr)
{
	t_file		*file;
	t_file_type	type;
	int			flags;
	t_token		*token;

	token = (*tokens_ptr)->data;
	if (token->type == T_REDIR_IN || token->type == T_REDIR_OUT
		|| token->type == T_REDIR_APPEND)
		type = FILE_REG;
	else if (token->type == T_HEREDOC)
		type = FILE_HEREDOC;
	if (token->type == T_REDIR_APPEND)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else if (token->type == T_REDIR_IN)
		flags = O_RDONLY;
	else if (token->type == T_REDIR_OUT)
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	token = (*tokens_ptr)->next->data;
	file = new_file(token->value, type, flags);
	return (file);
}
