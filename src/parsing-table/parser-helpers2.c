/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser-helpers2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:17:22 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/13 12:14:08 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	build_state_22_to_24(t_parsing_table *table)
{
	*(*table)++ = (t_step){22, T_WORD, A_SHIFT, T_WORD, 28};
	*(*table)++ = (t_step){22, T_HEREDOC, A_SHIFT, T_HEREDOC, 2};
	*(*table)++ = (t_step){22, T_REDIR_IN, A_SHIFT, T_REDIR_IN, 3};
	*(*table)++ = (t_step){22, T_REDIR_OUT, A_SHIFT, T_REDIR_OUT, 4};
	*(*table)++ = (t_step){22, T_REDIR_APPEND, A_SHIFT, T_REDIR_APPEND, 5};
	*(*table)++ = (t_step){22, T_ANY, A_REDUCE, 2, R_SIMPLE_COMMAND};
	*(*table)++ = (t_step){22, (t_token_type) R_IO_REDIRECT, A_NONE, 0, 29};
	*(*table)++ = (t_step){22, (t_token_type) R_IO_FILE, A_NONE, 0, 11};
	*(*table)++ = (t_step){22, (t_token_type) R_IO_HERE, A_NONE, 0, 12};
	*(*table)++ = (t_step){23, T_ANY, A_REDUCE, 1, R_CMD_SUFFIX};
	*(*table)++ = (t_step){24, T_ANY, A_REDUCE, 1, R_CMD_WORD};
}

void	build_state_25_to_29(t_parsing_table *table)
{
	*(*table)++ = (t_step){25, T_WORD, A_SHIFT, T_WORD, 21};
	*(*table)++ = (t_step){25, T_HEREDOC, A_SHIFT, T_HEREDOC, 2};
	*(*table)++ = (t_step){25, T_REDIR_IN, A_SHIFT, T_REDIR_IN, 3};
	*(*table)++ = (t_step){25, T_REDIR_OUT, A_SHIFT, T_REDIR_OUT, 4};
	*(*table)++ = (t_step){25, T_REDIR_APPEND, A_SHIFT, T_REDIR_APPEND, 5};
	*(*table)++ = (t_step){25, T_ANY, A_REDUCE, 2, R_SIMPLE_COMMAND};
	*(*table)++ = (t_step){25, (t_token_type) R_CMD_SUFFIX, A_NONE, 0, 30};
	*(*table)++ = (t_step){25, (t_token_type) R_IO_REDIRECT, A_NONE, 0, 23};
	*(*table)++ = (t_step){25, (t_token_type) R_IO_FILE, A_NONE, 0, 11};
	*(*table)++ = (t_step){25, (t_token_type) R_IO_HERE, A_NONE, 0, 12};
	*(*table)++ = (t_step){26, T_ANY, A_REDUCE, 2, R_CMD_PREFIX};
	*(*table)++ = (t_step){27, T_ANY, A_REDUCE, 3, R_PIPE_SEQUENCE};
	*(*table)++ = (t_step){28, T_ANY, A_REDUCE, 2, R_CMD_SUFFIX};
	*(*table)++ = (t_step){29, T_ANY, A_REDUCE, 2, R_CMD_SUFFIX};
}

void	build_state_30(t_parsing_table *table)
{
	*(*table)++ = (t_step){30, T_WORD, A_SHIFT, T_WORD, 28};
	*(*table)++ = (t_step){30, T_HEREDOC, A_SHIFT, T_HEREDOC, 2};
	*(*table)++ = (t_step){30, T_REDIR_IN, A_SHIFT, T_REDIR_IN, 3};
	*(*table)++ = (t_step){30, T_REDIR_OUT, A_SHIFT, T_REDIR_OUT, 4};
	*(*table)++ = (t_step){30, T_REDIR_APPEND, A_SHIFT, T_REDIR_APPEND, 5};
	*(*table)++ = (t_step){30, T_ANY, A_REDUCE, 3, R_SIMPLE_COMMAND};
	*(*table)++ = (t_step){30, (t_token_type) R_IO_REDIRECT, A_NONE, 0, 29};
	*(*table)++ = (t_step){30, (t_token_type) R_IO_FILE, A_NONE, 0, 11};
	*(*table)++ = (t_step){30, (t_token_type) R_IO_HERE, A_NONE, 0, 12};
}
