/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 07:40:35 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/12 08:32:38 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# define DEFAULT_STACK_SIZE 128

# include <stddef.h>

typedef struct s_stack
{
	int		*content;
	size_t	len;
	size_t	size;
}	t_stack;

/**
 * Initializes a new stack structure.
 *
 * @param size The size of the stack structure. If 0, the default will be used
 * @return A pointer to a stack structure on success, a NULL pointer on error
 */
t_stack	*new_stack(size_t size);

/**
 * Adds a new element at the top of a stack.
 *
 * @param stack A pointer to a stack structure
 * @param n The integer to put on top of the stack
 */
void	stack_shift(t_stack *stack, int n);

/**
 * Removes the element at the top of a stack.
 *
 * @param stack A pointer to a non-empty stack
 * @return The integer removed from the top of the stack.
 * Undefined if the given stack is empty
 */
int		stack_pop(t_stack *stack);

/**
 * Removes a number of elements from the top of a stack,
 * adding a new element afterwards.
 *
 * @param stack A pointer to a stack structure
 * @param reduce_len The number of elements to remove from the stack.
 * If greater than the number of elements in the stack,
 * the stack will be emptied
 * @param n The integer to put on top of the stack
 */
void	stack_reduce(t_stack *stack, size_t reduce_len, int n);

/**
 * Frees a stack structure
 *
 * @param A pointer to a stack structure
 */
void	free_stack(void *stack);

#endif // !STACK_H
