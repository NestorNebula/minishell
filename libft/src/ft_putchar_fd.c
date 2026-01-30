/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:17:16 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/10 09:31:27 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/**
 *  Outputs the character 'c' to the specified file descriptor.
 *
 *  @param c The character to output
 *  @param fd The file descriptor on which to write
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
