/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:20:04 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/05 08:29:46 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# define _GNU_SOURCE 1

# include "file.h"

/**
 * Reads lines of input until a line corresponding
 * to the given delimiter is read.
 * Stores the content read in the given file structure.
 *
 * @param delimiter The string to compare with each line read.
 * When encountered, the delimiter will stop the prompt.
 * @param hd_file A pointer to a file structure
 * @return On success, a file descriptor containing the content read.
 * -1 on failure.
 */
int	get_heredoc(const char *delimiter, t_file *hd_file);

#endif // !HEREDOC_H
