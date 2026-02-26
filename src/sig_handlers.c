/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:44:57 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/26 14:24:01 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <readline/readline.h>
#include <unistd.h>

volatile sig_atomic_t	g_signal;

void	sig_handler(int sig)
{
	g_signal = sig;
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	heredoc_sig_handler(int sig)
{
	g_signal = sig;
	if (sig == SIGINT)
	{
		close(STDIN_FILENO);
		write(1, "\n", 1);
	}
}

void	exec_sig_handler(int sig)
{
	g_signal = sig;
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n", 1);
}
