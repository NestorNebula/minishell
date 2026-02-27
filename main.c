#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "env.h"
#include "exec.h"
#include "libft.h"
#include "parser.h"
#include "prompt.h"
#include "shell.h"
#include "shell_signal.h"
#include "token.h"

#define SIGRC 128

extern volatile sig_atomic_t	g_signal;

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*line;

	(void) argc;
	(void) argv;
	init_shell(&shell, envp);
	while (shell.running)
	{
		g_signal = 0;
		set_default_signals();
		line = get_prompt();
		if (g_signal != 0)
			shell.last_status = SIGRC + g_signal;
		shell.cmds = parse(line, &shell);
		if (shell.cmds != NULL)
		{
			set_exec_signals();
			shell.last_status = exec(shell.cmds, &shell);
		}
		if (line == NULL)
			shell.running = 0;
		clear_dll(&shell.cmds, free_command);
		free(line);
	}
	clear_dll(&shell.env, free_env_var);
	rl_clear_history();
	return (shell.last_status);
}
