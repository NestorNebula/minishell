/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:09:38 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/26 13:48:32 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_SIGNAL_H
# define SHELL_SIGNAL_H

/**
 * Sets program's default signal setup.
 */
void	set_default_signals(void);

/**
 * Sets program's heredoc signal setup.
 */
void	set_heredoc_signals(void);

/**
 * Sets program's exec signal setup.
 */
void	set_exec_signals(void);

/**
 * The default signal handler.
 *
 * @param sig A signal
 */
void	sig_handler(int sig);

/**
 * The heredoc signal handler.
 *
 * @param sig A signal
 */
void	heredoc_sig_handler(int sig);

/**
 * The execution signal handler.
 *
 * @param sig A signal
 */
void	exec_sig_handler(int sig);

#endif // !SHELL_SIGNAL_H
