/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:26:08 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/04 10:04:53 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

typedef enum e_file_status {
	FILE_DEFAULT,
	FILE_OK,
	FILE_PDENIED,
	FILE_NOTFOUND,
	FILE_HEREDOC,
}				t_file_status;

typedef struct s_file {
	const char	*path;
	int			fd;
	int			status;
}				t_file;

/**
 * Initializes a new file structure.
 *
 * @param path The path to the file
 * @param fd The file descriptor
 * @param status The file status
 * @return A pointer to a file structure on success, NULL on error
 */
t_file	*new_file(const char *path, int fd, t_file_status status);

/**
 * Frees a file structure.
 *
 * @param file A pointer to a file structure
 */
void		free_file(void *file);

#endif // !FILE_H
