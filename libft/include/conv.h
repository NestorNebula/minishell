/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:03:00 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/03 10:37:34 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_H

# define CONV_H

# include <stdarg.h>
# include <stddef.h>
# include <stdbool.h>
# include "libft_string.h"

# define PREF_MAX_SIZE 4

typedef struct conv {
	size_t	width;
	size_t	prec;
	size_t	prec_len;
	int		flags;
	char	type;
	char	*val;
	size_t	val_len;
	char	pref[PREF_MAX_SIZE];
	size_t	pref_len;
	bool	err;
}		t_conv;

# define FLAGS "-0# +"
# define CONVS "cspdiuxX%"

# define DASH_F 0x01
# define DOT_F 0x02
# define HASHTAG_F 0x04
# define PLUS_F 0x08
# define SPACE_F 0x10
# define ZERO_F 0x20

# define CHAR_F DASH_F
# define STR_F 0x03
# define PTR_F 0x1b
# define INT_F 0x3b
# define UINT_F 0x23
# define XUINT_F 0x27
# define PERC_F 0x00

/**
 *  Reads conversion string and stores its informations in the given structure.
 *
 *  @param conv_str The string containing informations about the conversion
 *  @param conv A pointer to the conv structure that will store the informations
 *  @return The number of characters read to get the conversion's informations
 */
size_t	read_conv(const char *conv_str, t_conv *conv);

/**
 *	Checks conversion informations and removes potential forbidden flags
 *
 *	@param conv A pointer to the conv structure storing
 *	the conversion's informations
 *	@return True if the conversion is a valid conversion, false otherwise
 */
bool	check_conv(t_conv *conv);

/**
 *  Creates a duplicate of the next argument's string value using
 *  the conversion's type and stores it in the given structure.
 *
 *  @param ap A pointer to a variable argument list
 *  @param conv A pointer to the conv structure storing
 *  the conversion's informations
 *  @return A pointer to the conversion's value. NULL if the allocation fails
 */
char	*set_conv_val(va_list *ap, t_conv *conv);

/**
 *	Sets conversion prefix using the informations stored
 *	in the conversion structure.
 *
 *	@param conv A pointer to the conv structure storing
 *	the conversion's informations
 */
void	set_conv_pref(t_conv *conv);

/**
 *  Prints conversion to given file descriptor
 *
 *  @param conv A pointer to the conv structure storing
 *  the conversion's informations
 *  @param str The string in which the conversion must be stored
 *  @return The number of characters printed. -1 if an error occurred.
 */
int		print_conv(t_conv *conv, t_string *str);

#endif /* end of include guard: CONV_H */
