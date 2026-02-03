/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filepath.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 08:01:07 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/03 08:03:44 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEPATH_H
# define FILEPATH_H

/**
 * Searches for a file named filename using the environment variables.
 *
 * @param filename The name of the file to search
 * @return A dynamically allocated string containing the filepath 
 * if the file was found, a NULL pointer otherwise
 */
char	*find_filepath(const char *filename);

#endif // !FILEPATH_H
