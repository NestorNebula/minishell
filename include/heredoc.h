/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:20:04 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/27 09:32:20 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# define _GNU_SOURCE 1

# include "command.h"
# include "file.h"
# include "shell.h"

/**
 * Reads lines of input until a line corresponding
 * to the given delimiter is read.
 * Stores the content read in the given file structure.
 *
 * @param delimiter The string to compare with each line read.
 * When encountered, the delimiter will stop the prompt.
 * @param hd_file A pointer to a file structure
 * @param shell A pointer to a shell structure
 * @return On success, a file descriptor containing the content read.
 * -1 on failure.
 */
int	get_heredoc(const char *delimiter, t_file *hd_file, t_shell *shell);

/**
 * Opens the file to read and write the content of the heredoc,
 * storing two file descriptors in the given array.
 *
 * @param hd_pipe The array in which the file descriptors will be stored.
 * The first element will be for reading, the second for writing
 * @return 0 on success, -1 on error
 */
int	open_heredoc(t_pipe hd_pipe);

/**
 * Writes the given line to a file descriptor,
 * applying line expansion if needs be.
 *
 * @param line The string to write
 * @param delimiter The string that was used as heredoc delimiter
 * @param fd The file descriptor in which the content must be written
 * @param shell A pointer to a shell structure
 * @return 0 on success, > 0 on error
 */
int	handle_line(char *line, const char *delimiter, int fd, t_shell *shell);

#endif // !HEREDOC_H
