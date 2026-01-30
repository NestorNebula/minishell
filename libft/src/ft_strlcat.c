/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:40:18 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/11 13:42:12 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	j;

	if (siz == 0)
		return (ft_strlen(src));
	j = 0;
	while (dst[j] != '\0')
		j++;
	i = 0;
	while (src[i] != '\0' && i + j < siz - 1)
	{
		dst[i + j] = src[i];
		i++;
	}
	if (i + j < siz)
		dst[i + j] = '\0';
	while (src[i] != '\0')
		i++;
	if (j < siz)
		return (i + j);
	return (i + siz);
}
