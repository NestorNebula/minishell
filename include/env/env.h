/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:36:03 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/03 12:22:05 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "dll.h"

typedef struct s_env_var {
	const char	*key;
	char		*value;
}				t_env_var;

/**
 * Initializes a new env_var structure.
 *
 * @param key A string corresponding to the variable's key
 * @param value A string corresponding to the variable's value
 * @return A pointer to an env_var structure on success,
 * a NULL pointer on error
 */
t_env_var	*new_env_var(const char *key, char *value);

/**
 * Searches for an environment variable in a list of variables.
 *
 * @param env_vars A dll storing environment variables
 * @param key The key of the searched environment variable
 * @return A pointer to the searched env_var structure if found,
 * a NULL pointer otherwise
 */
t_env_var	*find_env_var(t_dll *env_vars, const char *key);

/**
 * Adds an environment variable to the environment variables list.
 * If a variable with the same key already exists, updates it instead of
 * creating a new one.
 *
 * @param env_vars_ptr A pointer to a dll
 * @param key A string corresponding to the variable's key
 * @param value A string corresponding to the variable's value
 * @return A pointer to the created/updated variable on success,
 * a NULL pointer on error
 */
t_env_var	*set_env_var(t_dll **env_vars_ptr, const char *key, char *value);

/**
 * Creates an array of environment variables from
 * a list of env_var structures.
 *
 * @param env A pointer to the first node of a dll structure
 * @return A pointer to the first element of
 * an array of environment variables on success, a null pointer otherwise
 */
char		**env_to_envp(t_dll *env);

/**
 * Creates a list of env_var structures from an array of
 * environment variables.
 *
 * @param envp A pointer to the first element of
 * an array of environment variables
 * @return A pointer to the first node of a dll structure
 */
t_dll		*envp_to_env(char **envp);

/**
 * Frees an array of environment variables.
 *
 * @param envp A pointer to the first element of
 * an array of environment variables
 */
void		free_envp(char **envp);

/**
 * Frees an env_var structure.
 *
 * @param env_var A pointer to an env_var structure
 */
void		free_env_var(void *env_var);

#endif // !ENV_H
