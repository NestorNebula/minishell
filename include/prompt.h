/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:13:38 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/24 16:16:19 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

/**
 * Reads a line from standard input and stores it in program's history.
 *
 * @return A pointer to the content read on success, a null pointer on error
 */
char	*get_prompt(void);

#endif // !PROMPT_H
