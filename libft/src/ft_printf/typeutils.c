/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:26:20 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/25 09:28:48 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "conv.h"

#define NULL_PTR "(nil)"
#define NULL_STR "(null)"

char	*get_char_val(char c)
{
	char	*val;

	val = malloc(2);
	if (val == NULL)
		return (NULL);
	val[0] = c;
	val[1] = '\0';
	return (val);
}

char	*get_ptr_val(void *ptr)
{
	if (ptr == NULL)
		return (ft_strdup(NULL_PTR));
	return (ft_pitoa_base(ptr, "0123456789abcdef"));
}

char	*get_str_val(const char *str, t_conv *conv)
{
	char	*val;
	size_t	str_len;

	if (str == NULL)
	{
		if ((conv->flags & DOT_F) && conv->prec < ft_strlen(NULL_STR))
			return (ft_strdup(""));
		return (ft_strdup(NULL_STR));
	}
	str_len = ft_strlen(str);
	if ((conv->flags & DOT_F) && str_len > conv->prec)
		str_len = conv->prec;
	val = (char *) malloc(sizeof(char) * (str_len + 1));
	if (val != NULL)
		ft_strlcpy(val, str, str_len + 1);
	return (val);
}

void	str_toupper(char *str)
{
	while (*str != '\0')
	{
		*str = ft_toupper(*str);
		str++;
	}
}
