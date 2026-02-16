/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 00:28:13 by cmonmire          #+#    #+#             */
/*   Updated: 2026/02/10 04:24:56 by cmonmire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token	*new_token(t_token_type type, char *value)
{
	t_token	*tok;

	if (!content)
		return ;
	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->type = type;
	tok->value = value;
	return (tok);
}

void	free_token(void *content)
{
	t_token	*tok;

	if (!content)
		return ;
	tok = (t_token *)content;
	free(tok->value);
	free(tok);
}
