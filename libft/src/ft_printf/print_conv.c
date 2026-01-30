/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:55:39 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/24 13:18:55 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "conv.h"
#include "string.h"
#include "typeutils.h"

static void	prepare_special_cases(t_conv *conv);

static int	handle_complex_conv(t_conv *conv, t_string *str);

static void	print_width(t_conv *conv, t_string *str);

static void	print_precision(t_conv *conv, t_string *str);

int		print_conv(t_conv *conv, t_string *str)
{
	if (conv->err)
	{
		string_cat(str, "%", 1);
		return (-1);
	}
	prepare_special_cases(conv);
	if (!(conv->flags & DOT_F) && !conv->width)
	{
		string_cat(str, conv->pref, conv->pref_len);
		string_cat(str, conv->val, conv->val_len);
		return (str->len);
	}
	return (handle_complex_conv(conv, str));
}

static void	prepare_special_cases(t_conv *conv)
{
	if (conv->type == 'X')
	{
		if (conv->pref_len > 0)
			str_toupper(conv->pref);
		str_toupper(conv->val);
	}
	else if (conv->type == 's' || conv->type == '%')
		conv->prec = 0;
	if (conv->type == '%')
		conv->width = 0;
	if (((conv->flags & DOT_F) && conv->type != 'p') || (conv->flags & DASH_F))
		conv->flags &= (~ZERO_F);
	if (conv->type == 'c')
		conv->val_len = 1;
	if (ft_strchr("pdiuxX", conv->type) && (conv->flags & DOT_F)
		&& conv->val[0] == '0')
		conv->val_len = 0;
}

static int	handle_complex_conv(t_conv *conv, t_string *str)
{
	if ((conv->flags & DOT_F) && conv->val_len < conv->prec)
		conv->prec_len = conv->prec;
	else
		conv->prec_len = conv->val_len;
	if (!(conv->flags & DASH_F) && !(conv->flags & ZERO_F))
		print_width(conv, str);
	string_cat(str, conv->pref, conv->pref_len);
	if (!(conv->flags & DASH_F) && (conv->flags & ZERO_F))
		print_width(conv, str);
	print_precision(conv, str);
	string_cat(str, conv->val, conv->val_len);
	if (conv->flags & DASH_F)
		print_width(conv, str);
	if (conv->width < conv->pref_len + conv->prec_len)
		conv->width = conv->pref_len + conv->prec_len;
	return (str->len);
}

static void	print_width(t_conv *conv, t_string *str)
{
	size_t	i;
	char	c;

	if ((conv->flags & ZERO_F) && !(conv->flags & DASH_F))
		c = '0';
	else
		c = ' ';
	i = conv->pref_len + conv->prec_len;
	while (i < conv->width)
	{
		string_cat(str, &c, 1);
		i++;
	}	
}

static void	print_precision(t_conv *conv, t_string *str)
{
	size_t	i;

	i = conv->val_len;
	while (i < conv->prec_len)
	{
		string_cat(str, "0", 1);
		i++;
	}
}
