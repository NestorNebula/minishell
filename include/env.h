/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:36:03 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/03 11:42:34 by nhoussie         ###   ########.fr       */
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
 * Frees an env_var structure.
 *
 * @param env_var A pointer to an env_var structure
 */
void		free_env_var(void *env_var);

#endif // !ENV_H
