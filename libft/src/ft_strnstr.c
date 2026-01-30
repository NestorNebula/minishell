/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:37:20 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/12 17:47:48 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_len;
	size_t	little_len;
	size_t	i;

	if (big == NULL || little == NULL)
		return (NULL);
	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *) big);
	if (big_len < little_len)
		return (NULL);
	i = 0;
	while (i + little_len <= len && i < big_len)
	{
		if (ft_strncmp(big + i, little, little_len) == 0)
			return ((char *) big + i);
		i++;
	}
	return (NULL);
}
