/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build-parsing-table.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:03:26 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/11 16:18:05 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "parser-helpers.h"

t_parsing_table	build_parsing_table(void)
{
	t_parsing_table	parsing_table;
	t_parsing_table	table_ptr;

	parsing_table = malloc(sizeof(t_step) * STEPS_COUNT);
	if (parsing_table == NULL)
		return (NULL);
	table_ptr = parsing_table;
	build_state_0(&table_ptr);
	build_state_1_to_7(&table_ptr);
	build_state_8_to_9(&table_ptr);
	build_state_10_to_19(&table_ptr);
	build_state_20_to_21(&table_ptr);
	build_state_22_to_24(&table_ptr);
	build_state_25_to_29(&table_ptr);
	build_state_30(&table_ptr);
	return (parsing_table);
}
