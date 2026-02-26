/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:49:34 by cmonmire          #+#    #+#             */
/*   Updated: 2026/02/09 23:50:18 by cmonmire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "dll.h"

typedef enum e_token_type
{
	T_END = -2,
	T_ANY,
	T_WORD,
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_REDIR_APPEND,
	T_HEREDOC,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
}	t_token;

/**
 * Initializes a new token structure.
 *
 * @param type The token's type
 * @param value The token's value
 * @return A pointer to a token structure on success, a null pointer on error
 */
t_token	*new_token(t_token_type type, char *value);

/**
 * Frees a token structure.
 *
 * @param content A pointer to a token structure
 */
void	free_token(void *content);

/**
 * Creates a list of tokens from the given line.
 *
 * @param line The string to use to create the list of tokens
 * @return A pointer to the first node of a dll structure of tokens on success,
 * a null pointer on error
 */
t_dll	*tokenizer(char *line);

#endif
