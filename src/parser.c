/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:00:21 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/12 12:44:27 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

#include <stdio.h>

static t_token_type	get_next_token(t_stack *stack, t_dll *tokens,
						int skip, t_token **token_ptr);

static t_step		*get_next_step(t_parser *parser, t_token_type token);

static t_token		*check_tokens(t_parser *parser, t_dll *tokens);

static void			do_step(t_parser *parser, t_dll **tokens,
						int *skipped_tokens);

t_token	*parse_tokens(t_dll *tokens, t_parsing_table parsing_table)
{
	t_parser		parser;
	t_token			*err_token;

	if (tokens == NULL || parsing_table == NULL)
		return (NULL);
	parser.stack = new_stack(dll_size(tokens));
	if (parser.stack == NULL)
		return (NULL);
	parser.parsing_table = parsing_table;
	parser.state = 0;
	parser.step = NULL;
	err_token = check_tokens(&parser, tokens);
	free_stack(parser.stack);
	return (err_token);
}

static t_token_type	get_next_token(t_stack *stack, t_dll *tokens,
						int skip, t_token **token_ptr)
{
	if (stack->len > (size_t) skip)
		return (stack->content[skip]);
	skip -= stack->len;
	while (skip > 0 && tokens != NULL)
	{
		tokens = tokens->next;
		skip--;
	}
	if (tokens == NULL || tokens->data == NULL)
		return (T_END);
	if (token_ptr != NULL)
		*token_ptr = tokens->data;
	return (((t_token *) tokens->data)->type);
}

static t_step	*get_next_step(t_parser *parser, t_token_type token)
{
	t_step	*step;
	size_t	i;

	step = NULL;
	i = 0;
	while (i < STEPS_COUNT && step == NULL)
	{
		step = &parser->parsing_table[i++];
		if (step->state != parser->state || step->token != token)
			step = NULL;
	}
	if (step != NULL)
		return (step);
	i = 0;
	while (i < STEPS_COUNT && step == NULL)
	{
		step = &parser->parsing_table[i++];
		if (step->state != parser->state
			|| (step->token != token && step->token != T_ANY))
			step = NULL;
	}
	return (step);
}

static t_token	*check_tokens(t_parser *parser, t_dll *tokens)
{
	t_token			*token;
	int				skip;
	t_token_type	token_type;

	skip = 0;
	token_type = get_next_token(parser->stack, tokens, skip, &token);
	parser->step = get_next_step(parser, token_type);
	while (parser->step != NULL && parser->step->action != A_ACCEPT)
	{
		do_step(parser, &tokens, &skip);
		token_type = get_next_token(parser->stack, tokens, skip, &token);
		parser->step = get_next_step(parser, token_type);
	}
	if (parser->step == NULL)
		return (token);
	return (NULL);
}

static void	do_step(t_parser *parser, t_dll **tokens, int *skipped_tokens)
{
	parser->state = parser->step->next_state;
	if (parser->step->action == A_SHIFT
		&& (size_t)(*skipped_tokens) >= parser->stack->len)
	{
		stack_shift(parser->stack, parser->step->action_arg);
		if (*tokens != NULL)
			*tokens = (*tokens)->next;
		(*skipped_tokens)++;
	}
	else if (parser->step->action == A_REDUCE)
	{
		stack_reduce(parser->stack, parser->step->action_arg,
			parser->step->next_state);
		parser->state = 0;
		*skipped_tokens = 0;
	}
	else
		(*skipped_tokens)++;
}
