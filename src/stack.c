/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 08:59:03 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/13 12:06:06 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"

t_stack	*new_stack(size_t size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->size = size;
	if (stack->size == 0)
		stack->size = DEFAULT_STACK_SIZE;
	stack->content = malloc(sizeof(int) * stack->size);
	if (stack->content == NULL)
	{
		free(stack);
		return (NULL);
	}
	stack->len = 0;
	return (stack);
}

void	stack_shift(t_stack *stack, int n)
{
	if (stack == NULL || stack->size == stack->len)
		return ;
	stack->content[stack->len++] = n;
}

int	stack_pop(t_stack *stack)
{
	if (stack == NULL || stack->len == 0)
		return (0);
	return (stack->content[--stack->len]);
}

void	stack_reduce(t_stack *stack, size_t reduce_len, int n)
{
	if (stack == NULL)
		return ;
	while (reduce_len > 0 && stack->len > 0)
	{
		(void) stack_pop(stack);
		reduce_len--;
	}
	stack_shift(stack, n);
}

void	free_stack(void *stack)
{
	if (stack != NULL)
	{
		free(((t_stack *) stack)->content);
		free(stack);
	}
}
