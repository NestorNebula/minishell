/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 09:06:21 by cmonmire          #+#    #+#             */
/*   Updated: 2026/03/01 15:00:59 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "token.h"

static int	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

static t_dll	*one_operator(char *line, int *i)
{
	t_dll	*tok_node;
	t_token	*tok;

	if (line[*i] == '<')
		tok = new_token(T_REDIR_IN, ft_strdup("<"));
	else if (line[*i] == '>')
		tok = new_token(T_REDIR_OUT, ft_strdup(">"));
	else
		tok = new_token(T_PIPE, ft_strdup("|"));
	(*i)++;
	if (tok == NULL)
		return (NULL);
	if (tok->value == NULL)
	{
		free(tok);
		return (NULL);
	}
	tok_node = new_dll(tok);
	if (tok_node == NULL)
		free_token(tok);
	return (tok_node);
}

static t_dll	*double_operator(char *line, int *i)
{
	t_dll	*tok_node;
	t_token	*tok;

	if (line[*i] == '<' && line[*i + 1] == '<')
		tok = new_token(T_HEREDOC, ft_strdup("<<"));
	else
		tok = new_token(T_REDIR_APPEND, ft_strdup(">>"));
	*i += 2;
	if (tok == NULL)
		return (NULL);
	if (tok->value == NULL)
	{
		free(tok);
		return (NULL);
	}
	tok_node = new_dll(tok);
	if (tok_node == NULL)
		free_token(tok);
	return (tok_node);
}

static t_dll	*handle_token(char *line, int *i);

t_dll	*tokenizer(char *line)
{
	t_dll	*tokens;
	t_dll	*tok_node;
	int		i;

	tokens = NULL;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
		{
			tok_node = handle_token(line, &i);
			if (tok_node == NULL)
			{
				clear_dll(&tokens, free_token);
				return (NULL);
			}
			add_dll(&tokens, tok_node);
		}
	}
	return (tokens);
}

static t_dll	*handle_token(char *line, int *i)
{
	t_dll	*tok_node;
	t_token	*tok;

	if (is_operator(line[*i]))
	{
		if (line[*i] == line[*i + 1] && line[*i] != '|')
			tok_node = double_operator(line, i);
		else
			tok_node = one_operator(line, i);
	}
	else
	{
		tok = new_token(T_WORD, read_word(line, i));
		if (tok == NULL)
			return (NULL);
		if (tok->value == NULL)
		{
			free(tok);
			return (NULL);
		}
		tok_node = new_dll(tok);
		if (tok_node == NULL)
			free_token(tok);
	}
	return (tok_node);
}
