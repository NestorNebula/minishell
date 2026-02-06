/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:26:04 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/06 10:46:49 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLL_H
# define DLL_H

# include <stddef.h>

typedef struct s_dll {
	struct s_dll	*prev;
	struct s_dll	*next;
	void			*data;
}				t_dll;

/**
 * Initializes a new dll stucture with the given data.
 *
 * @param data The data to store in the new dll
 * @return A pointer to a dll structure on success, NULL on error
 */
t_dll		*new_dll(void *data);

/**
 * Adds a dll node to the end of a given dll.
 *
 * @param dll_ptr A pointer to the first node of a dll
 * @param new_dll A pointer to a dll node
 */
void		add_dll(t_dll **dll_ptr, t_dll *new_dll);

/**
 * Gives the number of nodes in a dll.
 *
 * @param dll A pointer to the first node of a dll
 * @return The size (number of nodes) of the given dll
 */
size_t		dll_size(t_dll *dll);

/**
 * Finds the last node in a dll.
 *
 * @param dll A pointer to the first node of a dll
 * @return The last node of the given dll. NULL if there is no node in the dll
 */
t_dll		*dll_last(t_dll *dll);

/**
 * Frees a dll node.
 *
 * @param dll A pointer to the first node of a dll
 * @param del A pointer to a function that will be used to
 * free the dll's data. If NULL, the dll's data won't be freed
 */
void		free_dll(t_dll *dll, void (*del)(void *));

/**
 * Frees all the nodes in a dll.
 *
 * @param dll A pointer to a dll
 * @param del A pointer to a function that will be used to
 * free each dll node's data. If NULL, each node's data won't be freed
 */
void		clear_dll(t_dll **dll, void (*del)(void *));

/**
 * Calls a function on each node of a dll.
 *
 * @param dll A pointer to the first node of a dll
 * @param f A pointer to a function that will be called on each dll node
 */
void		dll_for_each(t_dll *dll, void (*f)(void *));

#endif // !DLL_H
