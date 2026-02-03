/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:26:08 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/02 14:26:10 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_H
# define FD_H

typedef enum e_fd_status {
	FD_SUCCESS = 0,
	FD_PDENIED = 126,
	FD_NOTFOUND = 127,
}				t_fd_status;

typedef struct s_fd {
	int	fd;
	int	status;
}				t_fd;

/**
 * Initializes a new fd structure.
 *
 * @param fd The file descriptor to store in the fd structure
 * @param status The status to store in the fd structure
 * @return A pointer to a fd structure on success, NULL on error
 */
t_fd		*new_fd(int fd, int status);

/**
 * Frees a fd structure.
 *
 * @param fd A pointer to a fd structure
 */
void		free_fd(void *fd);

#endif // !FD_H
