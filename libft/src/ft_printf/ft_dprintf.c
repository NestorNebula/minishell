/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:23:35 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/25 09:43:06 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "conv.h"

static void	handle_char(char c, t_string *str);

static void	handle_conversion(const char **format, t_string *str,
				va_list *ap);

static int	handle_output(int fd, t_string *str);


/**
 *  Writes formatted output to a file descriptor using format
 *  and others arguments.
 *
 *  @param fd The file descriptor to which the output will be printed
 *  @param format The format of the output
 *  @param ... Optional arguments to use in combination with the format
 *  @return The number of characters printed. -1 if an error occurs
 */
int	ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	t_string	*str;

	if (format == NULL)
		return (-1);
	str = new_string();
	if (str == NULL)
		return (-1);
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
			handle_char(*format++, str);
		else
			handle_conversion(&format, str, &ap);
	}
	va_end(ap);
	return (handle_output(fd, str));

}

static void	handle_char(char c, t_string *str)
{
	string_cat(str, &c, 1);
}

static void	handle_conversion(const char **format, t_string *str,
				va_list *ap)
{
	t_conv	conv;

	(*format)++;
	*format += read_conv(*format, &conv);
	check_conv(&conv);
	if (conv.err)
	{
		if (conv.type != '\0')
			handle_char('%', str);
	}
	else if (set_conv_val(ap, &conv) != NULL)
	{
		set_conv_pref(&conv);
		print_conv(&conv, str);
		free(conv.val);
	}
}

static int	handle_output(int fd, t_string *str)
{
	int	res;

	res = write(fd, str->content, str->len);
	free_string(str);
	return (res);
}
