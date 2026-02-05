/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:26:08 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/04 15:31:22 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

typedef enum e_file_status {
	FILE_DEF,
	FILE_OK,
	FILE_ERR,
}				t_file_status;

typedef enum e_file_type {
	FILE_REG,
	FILE_STD,
	FILE_PIPE,
	FILE_HEREDOC,
}				t_file_type;

typedef struct s_file {
	const char		*path;
	int				fd;
	int				flags;
	t_file_status	status;
	t_file_type		type;
	int				err_code;
}				t_file;

/**
 * Initializes a new file structure.
 *
 * @param path The path to the file
 * @param type The file type 
 * @param flags The flags to use when opening the file
 * @return A pointer to a file structure on success, NULL on error
 */
t_file	*new_file(const char *path, t_file_type type, int flags);

/**
 * Frees a file structure.
 *
 * @param file A pointer to a file structure
 */
void		free_file(void *file);

#endif // !FILE_H
