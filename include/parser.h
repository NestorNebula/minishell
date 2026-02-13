/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:27:07 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/12 11:14:47 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "dll.h"
# include "stack.h"
# include "token.h"

# define STATES_COUNT 31
# define RULES_COUNT 11
# define STEPS_COUNT 100

typedef enum e_action
{
	A_NONE,
	A_SHIFT,
	A_REDUCE,
	A_ACCEPT,
}	t_action;

typedef enum e_rule
{
	R_PIPE_SEQUENCE = STATES_COUNT,
	R_SIMPLE_COMMAND,
	R_CMD_NAME,
	R_CMD_WORD,
	R_CMD_PREFIX,
	R_CMD_SUFFIX,
	R_IO_REDIRECT,
	R_IO_FILE,
	R_FILENAME,
	R_IO_HERE,
	R_HERE_END,
}	t_rule;

typedef struct s_step
{
	int				state;
	t_token_type	token;
	t_action		action;
	int				action_arg;
	int				next_state;
}	t_step;

typedef t_step	*t_parsing_table;

typedef struct s_parser
{
	t_parsing_table	parsing_table;
	int				state;
	t_step			*step;
	t_stack			*stack;
}	t_parser;

/**
 * Initializes a parsing table and sets every step inside of it.
 *
 * @return A pointer to the first step of the parsing table on success,
 * a NULL pointer on error
 */
t_parsing_table	build_parsing_table(void);

/**
 * Parses a list of tokens using a given parsing table.
 *
 * @param tokens A pointer to the first element of a dll
 * @param parsing_table A pointer to the first step of a parsing table
 * @return If the given list of tokens is valid, a NULL pointer is returned,
 * else, a pointer to the token that caused the list to be invalid is returned
 */
t_token			*parse_tokens(t_dll *tokens, t_parsing_table parsing_table);

#endif // !PARSER_H
