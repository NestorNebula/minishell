/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 09:06:21 by cmonmire          #+#    #+#             */
/*   Updated: 2026/02/11 11:57:10 by cmonmire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "dll.h"

static char	*read_word(char *line, int *i)
{
	int		start;
	char	quote;

	start = *i;
	quote = 0;
	while (line[*i])
	{
		if (!quote && (line[*i] == '\'' || line[*i] == '"'))
			quote = line[*i];
		else if (quote && line[*i] == quote)
			quote = 0;
		else if (!quote && (line[*i] == ' ' || line[*i] == '\t'
			|| line[*i] == '|' || line[*i] == '<' || line[*i] == '>'))
			break ;
		(*i)++;
	}
	return (ft_substr(line, start, *i - start));
}

static int	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

static void	*one_operator(t_dll **tokens, char *line, int *i)
{
	t_token	*tok;

	if (line[*i] == '<')
	{
		tok = new_token(T_REDIR_IN, ft_strdup("<"));
		(*i)++;
	}
	else if (line[*i] == '>')
	{
		tok = new_token(T_REDIR_OUT, ft_strdup(">"));
		(*i)++;
	}
	else
	{
		tok = new_token(T_PIPE, ft_strdup("|"));
		(*i)++;
	}
	tokens = add_dll(&tokens, new_dll(tok));
}

static void	*double_operator(t_dll **tokens, char *line, int *i)
{
	t_token	*tok;

	if (line[*i] == '<' && line[*i + 1] == '<')
	{
		tok = new_token(T_HEREDOC, ft_strdup("<<"));
		*i += 2;
	}
	else
	{
		tok = new_token(T_REDIR_APPEND, ft_strdup(">>"));
		*i += 2;
	}
	tokens = add_dll(&tokens, new_dll(tok));
}

t_dll	*tokenizer(char *line)
{
	t_dll	*tokens;
	t_token	*tok;
	int		i;

	tokens = NULL;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else if (is_operator(line[i]))
		{
			if (line[i] == line[i + 1])
				double_operator(&tokens, line[i], &i);
			else
				one_operator(&tokens, line[i], &i);
		}
		else
		{
			tok = new_token(T_WORD, read_word(line, &i));
			add_dll(&tokens, new_dll(tok));
		}
	}
	return (tokens);
}
