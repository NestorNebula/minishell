/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:14:30 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/13 12:05:43 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HELPERS_H
# define PARSER_HELPERS_H

# include "parser.h"

void	build_state_0(t_parsing_table *table);
void	build_state_1_to_7(t_parsing_table *table);
void	build_state_8_to_9(t_parsing_table *table);
void	build_state_10_to_19(t_parsing_table *table);
void	build_state_20_to_21(t_parsing_table *table);
void	build_state_22_to_24(t_parsing_table *table);
void	build_state_25_to_29(t_parsing_table *table);
void	build_state_30(t_parsing_table *table);

#endif // !PARSER_HELPERS_H
