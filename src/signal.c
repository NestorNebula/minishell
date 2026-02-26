/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:14:09 by cmonmire          #+#    #+#             */
/*   Updated: 2026/02/26 14:22:27 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "shell_signal.h"

static void	set_signals(void (*handler)(int));

void	set_default_signals(void)
{
	set_signals(sig_handler);
}

void	set_heredoc_signals(void)
{
	set_signals(heredoc_sig_handler);
}

void	set_exec_signals(void)
{
	set_signals(exec_sig_handler);
}

static void	set_signals(void (*handler)(int))
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
}
