/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft-string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:35:28 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/03 10:37:44 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "libft_string.h"

#define DEF_SIZE 4096

t_string	*new_string(void)
{
	t_string	*str;

	str = malloc(sizeof(t_string));
	if (str == NULL)
		return (NULL);
	str->content = malloc(sizeof(char) * DEF_SIZE);
	if (str->content == NULL)
	{
		free(str);
		return (NULL);
	}
	str->content[0] = '\0';
	str->len = 0;
	str->size = DEF_SIZE;
	return (str);
}

char	*string_cat(t_string *str_ptr, const char *str, size_t str_len)
{
	char	*resized_str;
	size_t	new_size;

	if (str_ptr == NULL || str_ptr->content == NULL || str == NULL)
		return (NULL);
	if (str_ptr->len + str_len >= str_ptr->size)
	{
		new_size = str_ptr->len + str_len + 1;
		resized_str = malloc(sizeof(char) * (new_size));
		if (resized_str == NULL)
			return (NULL);
		ft_strlcpy(resized_str, str_ptr->content, new_size);
		free(str_ptr->content);
		str_ptr->content = resized_str;
		str_ptr->size *= 2;
	}
	ft_strlcpy(str_ptr->content + str_ptr->len, str, str_len + 1);
	str_ptr->len += str_len;
	return (str_ptr->content);
}

void	free_string(t_string *str_ptr)
{
	if (str_ptr != NULL)
	{
		free(str_ptr->content);
		free(str_ptr);
	}
}
