/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:40:16 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/27 14:55:40 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "command.h"
# include "shell.h"

/**
 * Expands the arguments of the given command.
 *
 * @param command A pointer to a command structure
 * @param shell A pointer to a shell structure
 * @return A pointer to the first element of an array of strings containing
 * the expanded arguments on success, a null pointer on error
 */
char	**expand_args(t_command *command, t_shell *shell);

/**
 * Expands the given string by replacing the environment variables it stores
 * by their values.
 *
 * @param str The string to expand
 * @param shell A pointer to a shell structure
 * @return A pointer to the expanded string on success,
 * a null pointer on error
 */
char	*expand_string(char *str, t_shell *shell);

/**
 * Concatenates two strings.
 *
 * @param s1 A pointer to the first string
 * @param s2 A pointer to the second string
 * @return A pointer to a concatenation of both strings on success,
 * a null pointer on error
 */
char	*append_str(char *s1, char *s2);

/**
 * Appends a character to the given string.
 *
 * @param s A string to which the character will be appended
 * @param c The character to append
 * @return A pointer to the updated string
 */
char	*append_char(char *s, char c);

/**
 * Reads a variable name from a string
 *
 * @param str A string
 * @param i A pointer to the index of the start of the variable in the string 
 * @return A pointer to a string containing the variable
 */
char	*read_var_name(char *str, int *i);

/**
 * Searches the shell's environment variable to find the value corresponding
 * to the given key.
 *
 * @param shell A pointer to a shell structure
 * @param key The key for which to search in the environment variables
 * @return A pointer to the corresponding value if found,
 * a null pointer otherwise
 */
char	*get_env_value(t_shell *shell, char *key);

/**
 * Creates a copy of the given string from which
 * the quotes have been removed.
 *
 * @param str A pointer to a string
 * @return A copy of the given string without quotes on success,
 * a null pointer on error
 */
char	*remove_quotes(char *str);

#endif // !EXPANSION_H
