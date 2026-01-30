/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:59:21 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/25 09:43:47 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "conv.h"
#include "typeutils.h"

static void		set_flag(t_conv *conv, char f);

size_t	read_conv(const char *conv_str, t_conv *conv)
{
	size_t	i;

	if (conv == NULL)
		return (0);
	ft_bzero(conv, sizeof(t_conv));
	i = 0;
	while (conv_str[i] != '\0' && ft_strchr(FLAGS, conv_str[i]) != NULL)
		set_flag(conv, conv_str[i++]);
	while (ft_isdigit(conv_str[i]))
		conv->width = conv->width * 10 + conv_str[i++] - '0';
	if (conv_str[i] == '.')
	{
		conv->flags |= DOT_F;
		i++;
		while (ft_isdigit(conv_str[i]))
			conv->prec = conv->prec * 10 + conv_str[i++] - '0';
	}
	conv->type = conv_str[i++];
	if (conv->type == '\0' || ft_strchr(CONVS, conv->type) == NULL)
		return (0);
	return (i);
}

bool	check_conv(t_conv *conv)
{
	if (conv->type == 'c')
		conv->flags &= CHAR_F;
	else if (conv->type == 's')
		conv->flags &= STR_F;
	else if (conv->type == 'p')
		conv->flags &= PTR_F;
	else if (conv->type == 'd' || conv->type == 'i')
		conv->flags &= INT_F;
	else if (conv->type == 'u')
		conv->flags &= UINT_F;
	else if (conv->type == 'x' || conv->type == 'X')
		conv->flags &= XUINT_F;
	else if (conv->type == '%')
		conv->flags &= PERC_F;
	else
	{
		conv->err = true;
		return (false);
	}
	conv->err = false;
	return (true);
}

char	*set_conv_val(va_list *ap, t_conv *conv)
{
	if (conv->type == 'c')
		conv->val = get_char_val((char) va_arg(*ap, int));
	else if (conv->type == 's')
		conv->val = get_str_val((char *) va_arg(*ap, char *), conv);
	else if (conv->type == 'p')
		conv->val = get_ptr_val((void *) va_arg(*ap, void *));
	else if (conv->type == 'd' || conv->type == 'i')
		conv->val = ft_itoa_base((int) va_arg(*ap, int), "0123456789");
	else if (conv->type == 'u')
		conv->val = ft_uitoa_base((unsigned int) va_arg(*ap, unsigned int),
				"0123456789");
	else if (conv->type == 'x' || conv->type == 'X')
		conv->val = ft_uitoa_base((unsigned int) va_arg(*ap, unsigned int),
				"0123456789abcdef");
	else if (conv->type == '%')
		conv->val = get_char_val('%');
	if (conv->val != NULL)
		conv->val_len = ft_strlen(conv->val);
	else
		conv->err = true;
	return (conv->val);
}

void	set_conv_pref(t_conv *conv)
{
	char	*dup;

	conv->pref_len = 0;
	if (conv->err)
		return ;
	if (ft_strchr("di", conv->type) && conv->val[0] == '-')
	{
		conv->pref_len += ft_strlcpy(conv->pref, "-", 2);
		dup = ft_strdup(conv->val + 1);
		if (dup == NULL)
			conv->err = true;
		else
		{
			free(conv->val);
			conv->val = dup;
			conv->val_len--;
		}
	}
	else if (conv->flags & PLUS_F)
		conv->pref_len += ft_strlcpy(conv->pref, "+", 2);
	else if (conv->flags & SPACE_F)
		conv->pref_len += ft_strlcpy(conv->pref, " ", 2);
	if (((conv->flags & HASHTAG_F) || (conv->type == 'p'
				&& conv->val[0] != '(')) && conv->val[0] != '0')
		conv->pref_len += ft_strlcpy(conv->pref + conv->pref_len, "0x", 3);
}

static void	set_flag(t_conv *conv, char f)
{
	if (f == '-')
		conv->flags |= DASH_F;
	else if (f == '#')
		conv->flags |= HASHTAG_F;
	else if (f == '+')
		conv->flags |= PLUS_F;
	else if (f == ' ')
		conv->flags |= SPACE_F;
	else if (f == '0')
		conv->flags |= ZERO_F;
}
