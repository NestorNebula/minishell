#include <readline/readline.h>
#include "env.h"
#include "shell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void) argc;
	(void) argv;
	init_shell(&shell, envp);
	shell_loop(&shell);
	clear_dll(&shell.env, free_env_var);
	rl_clear_history();
	return (shell.last_status);
}
