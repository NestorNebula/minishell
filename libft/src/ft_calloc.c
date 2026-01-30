/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:55:40 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/12 13:00:58 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb * size == 0)
		return (malloc(0));
	if (SIZE_MAX / nmemb < size)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, size * nmemb);
	return (p);
}
