/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeutils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:15:56 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/19 12:46:41 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEUTILS_H

# define TYPEUTILS_H

/**
 *	Converts character to a string.
 *
 *	@param c The character to be converted
 *	@return The string containing the character. NULL if the allocation fails
 */
char	*get_char_val(char c);

/**
 *	Duplicates string to a valid conversion val
 *	using the informations stored in the conv structure.
 *	Stores special value for NULL string.
 *
 *	@param str The string to be duplicated
 *	@param conv The structure storing the conversion's informations
 *	@return The duplicated string. NULL if the allocation fails
 */
char	*get_str_val(const char *str, t_conv *conv);

/**
 *	Converts pointer's value to a string. Stores special value for NULL pointer.
 *
 *	@param ptr The pointer to be converted
 *	@return The string representation of the pointer's value.
 *	NULL if the allocation fails
 */
char	*get_ptr_val(void *ptr);

/**
 *  Puts every character in the string to its uppercase value
 *
 *  @param str The string to modify
 */
void	str_toupper(char *str);

#endif /* end of include guard: TYPEUTILS_H */
