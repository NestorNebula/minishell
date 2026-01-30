/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:36:52 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/27 14:45:29 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif /* ifndef BUFFER_SIZE */

typedef struct content {
	int		fd;
	char	buf[BUFFER_SIZE + 1];
	size_t	buf_len;
	char	*line;
	size_t	line_len;
	size_t	line_size;
}		t_content;

typedef struct gnl_list {
	struct gnl_list	*prev;
	struct gnl_list	*next;
	t_content		cont;
}		t_gnl_list;

/**
 *	Reads fd until reaching a new line character or the end of the file.
 *
 *	@param fd The file descriptor to read from
 *	@return The line read. NULL if there is nothing else to read or
 *	an error occurred
 */
char		*get_next_line(int fd);

/**
 *	Allocates memory (using malloc(3)) and returns a new node.
 *
 *	@param fd The file descriptor to store in the new node
 *	@return A pointer to the new node. NULL if the allocation fails
 */
t_gnl_list	*gnl_lst_new(int fd);

/**
 *  Adds the node 'new' at the end of the list.
 *
 *  @param lst The address of a pointer to the first node of a list
 *  @param new A pointer to the new node to be added
 */
void		gnl_lst_add(t_gnl_list **lst, t_gnl_list *new);

/**
 *	Frees the node and its content. Links the previous node to the next one.
 *
 *	@param lst A pointer to a node
 *	@param free_all If true, frees every node following the given node
 */
void		gnl_lst_free(t_gnl_list *lst, bool free_all);

/**
 *  Finds the first element of the list with a corresponding fd.
 *
 *  @param lst A pointer to the first node of a list
 *  @param fd The file descriptor to search in the list
 *  @return A pointer to the first corresponding node if found, NULL otherwise
 */
t_gnl_list	*gnl_lst_find(t_gnl_list *lst, int fd);

/**
 *  Copies content from src to dest.
 *
 *  @param dest The string to write into
 *  @param src The string from which to read
 *  @return The number of character copied
 */
size_t		ft_strcpy(char *dest, const char *src);

#endif /* end of include guard: GET_NEXT_LINE_H */
