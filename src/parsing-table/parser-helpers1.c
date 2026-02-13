/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser-helpers1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:13:45 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/13 12:13:50 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	build_state_0(t_parsing_table *table)
{
	*(*table)++ = (t_step){0, T_WORD, A_SHIFT, T_WORD, 1};
	*(*table)++ = (t_step){0, T_HEREDOC, A_SHIFT, T_HEREDOC, 2};
	*(*table)++ = (t_step){0, T_REDIR_IN, A_SHIFT, T_REDIR_IN, 3};
	*(*table)++ = (t_step){0, T_REDIR_OUT, A_SHIFT, T_REDIR_OUT, 4};
	*(*table)++ = (t_step){0, T_REDIR_APPEND, A_SHIFT, T_REDIR_APPEND, 5};
	*(*table)++ = (t_step){0, (t_token_type) R_PIPE_SEQUENCE, A_NONE, 0, 6};
	*(*table)++ = (t_step){0, (t_token_type) R_SIMPLE_COMMAND, A_NONE, 0, 7};
	*(*table)++ = (t_step){0, (t_token_type) R_CMD_NAME, A_NONE, 0, 8};
	*(*table)++ = (t_step){0, (t_token_type) R_CMD_PREFIX, A_NONE, 0, 9};
	*(*table)++ = (t_step){0, (t_token_type) R_IO_REDIRECT, A_NONE, 0, 10};
	*(*table)++ = (t_step){0, (t_token_type) R_IO_FILE, A_NONE, 0, 11};
	*(*table)++ = (t_step){0, (t_token_type) R_IO_HERE, A_NONE, 0, 12};
}

void	build_state_1_to_7(t_parsing_table *table)
{
	*(*table)++ = (t_step){1, T_ANY, A_REDUCE, 1, R_CMD_NAME};
	*(*table)++ = (t_step){2, T_WORD, A_SHIFT, T_WORD, 13};
	*(*table)++ = (t_step){2, (t_token_type) R_HERE_END, A_NONE, 0, 14};
	*(*table)++ = (t_step){3, T_WORD, A_SHIFT, T_WORD, 15};
	*(*table)++ = (t_step){3, (t_token_type) R_FILENAME, A_NONE, 0, 16};
	*(*table)++ = (t_step){4, T_WORD, A_SHIFT, T_WORD, 15};
	*(*table)++ = (t_step){4, (t_token_type) R_FILENAME, A_NONE, 0, 17};
	*(*table)++ = (t_step){5, T_WORD, A_SHIFT, T_WORD, 15};
	*(*table)++ = (t_step){5, (t_token_type) R_FILENAME, A_NONE, 0, 18};
	*(*table)++ = (t_step){6, T_END, A_SHIFT, T_END, 19};
	*(*table)++ = (t_step){6, T_PIPE, A_SHIFT, T_PIPE, 20};
	*(*table)++ = (t_step){7, T_ANY, A_REDUCE, 1, R_PIPE_SEQUENCE};
}

void	build_state_8_to_9(t_parsing_table *table)
{
	*(*table)++ = (t_step){8, T_WORD, A_SHIFT, T_WORD, 21};
	*(*table)++ = (t_step){8, T_HEREDOC, A_SHIFT, T_HEREDOC, 2};
	*(*table)++ = (t_step){8, T_REDIR_IN, A_SHIFT, T_REDIR_IN, 3};
	*(*table)++ = (t_step){8, T_REDIR_OUT, A_SHIFT, T_REDIR_OUT, 4};
	*(*table)++ = (t_step){8, T_REDIR_APPEND, A_SHIFT, T_REDIR_APPEND, 5};
	*(*table)++ = (t_step){8, T_ANY, A_REDUCE, 1, R_SIMPLE_COMMAND};
	*(*table)++ = (t_step){8, (t_token_type) R_CMD_SUFFIX, A_NONE, 0, 22};
	*(*table)++ = (t_step){8, (t_token_type) R_IO_REDIRECT, A_NONE, 0, 23};
	*(*table)++ = (t_step){8, (t_token_type) R_IO_FILE, A_NONE, 0, 11};
	*(*table)++ = (t_step){8, (t_token_type) R_IO_HERE, A_NONE, 0, 12};
	*(*table)++ = (t_step){9, T_WORD, A_SHIFT, T_WORD, 24};
	*(*table)++ = (t_step){9, T_HEREDOC, A_SHIFT, T_HEREDOC, 2};
	*(*table)++ = (t_step){9, T_REDIR_IN, A_SHIFT, T_REDIR_IN, 3};
	*(*table)++ = (t_step){9, T_REDIR_OUT, A_SHIFT, T_REDIR_OUT, 4};
	*(*table)++ = (t_step){9, T_REDIR_APPEND, A_SHIFT, T_REDIR_APPEND, 5};
	*(*table)++ = (t_step){9, T_ANY, A_REDUCE, 1, R_SIMPLE_COMMAND};
	*(*table)++ = (t_step){9, (t_token_type) R_CMD_WORD, A_NONE, 0, 25};
	*(*table)++ = (t_step){9, (t_token_type) R_IO_REDIRECT, A_NONE, 0, 26};
	*(*table)++ = (t_step){9, (t_token_type) R_IO_FILE, A_NONE, 0, 11};
	*(*table)++ = (t_step){9, (t_token_type) R_IO_HERE, A_NONE, 0, 12};
}

void	build_state_10_to_19(t_parsing_table *table)
{
	*(*table)++ = (t_step){10, T_ANY, A_REDUCE, 1, R_CMD_PREFIX};
	*(*table)++ = (t_step){11, T_ANY, A_REDUCE, 1, R_IO_REDIRECT};
	*(*table)++ = (t_step){12, T_ANY, A_REDUCE, 1, R_IO_REDIRECT};
	*(*table)++ = (t_step){13, T_ANY, A_REDUCE, 1, R_HERE_END};
	*(*table)++ = (t_step){14, T_ANY, A_REDUCE, 2, R_IO_HERE};
	*(*table)++ = (t_step){15, T_ANY, A_REDUCE, 1, R_FILENAME};
	*(*table)++ = (t_step){16, T_ANY, A_REDUCE, 2, R_IO_FILE};
	*(*table)++ = (t_step){17, T_ANY, A_REDUCE, 2, R_IO_FILE};
	*(*table)++ = (t_step){18, T_ANY, A_REDUCE, 2, R_IO_FILE};
	*(*table)++ = (t_step){19, T_ANY, A_ACCEPT, 0, 0};
}

void	build_state_20_to_21(t_parsing_table *table)
{
	*(*table)++ = (t_step){20, T_WORD, A_SHIFT, T_WORD, 1};
	*(*table)++ = (t_step){20, T_HEREDOC, A_SHIFT, T_HEREDOC, 2};
	*(*table)++ = (t_step){20, T_REDIR_IN, A_SHIFT, T_REDIR_IN, 3};
	*(*table)++ = (t_step){20, T_REDIR_OUT, A_SHIFT, T_REDIR_OUT, 4};
	*(*table)++ = (t_step){20, T_REDIR_APPEND, A_SHIFT, T_REDIR_APPEND, 5};
	*(*table)++ = (t_step){20, (t_token_type) R_SIMPLE_COMMAND, A_NONE, 0, 27};
	*(*table)++ = (t_step){20, (t_token_type) R_CMD_NAME, A_NONE, 0, 8};
	*(*table)++ = (t_step){20, (t_token_type) R_CMD_PREFIX, A_NONE, 0, 9};
	*(*table)++ = (t_step){20, (t_token_type) R_IO_REDIRECT, A_NONE, 0, 10};
	*(*table)++ = (t_step){20, (t_token_type) R_IO_FILE, A_NONE, 0, 11};
	*(*table)++ = (t_step){20, (t_token_type) R_IO_HERE, A_NONE, 0, 12};
	*(*table)++ = (t_step){21, T_ANY, A_REDUCE, 1, R_CMD_SUFFIX};
}
