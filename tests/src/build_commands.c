#include <stdlib.h>
#include <string.h>
#include "build_commands.h"
#include "command.h"
#include "cut.h"
#include "file.h"
#include "token.h"

static t_dll	*tokens_from_array(t_token *tokens_arr, size_t size);

static void	build_commands_test(void);

static void	init_build_commands_test(t_token *tokens_arr, size_t size,
				t_unit_test **unit_test_ptr, const char *test,
				t_dll **commands_ptr);

static void	build_commands_basic_tests(t_dll *commands, size_t expected_size,
				const char **commands_name, t_unit_test *unit_test);

static void	build_commands_args_tests(char **command_args,
				char **expected_args, size_t expected_args_size,
				t_unit_test *unit_test, const char *test);

static void	build_commands_fd_tests(t_dll *files,
				t_file_type *expected_files_type,
				char **expected_files_path, size_t expected_files_size,
				t_unit_test *unit_test, const char *test);

int	main(void)
{
	build_commands_test();
}

static t_dll	*tokens_from_array(t_token *tokens_arr, size_t size)
{
	t_dll	*tokens;
	t_token	*token;
	size_t	i;

	tokens = NULL;
	i = 0;
	while (i < size)
	{
		token = malloc(sizeof(t_token));
		if (token == NULL)
			break ;
		*token = tokens_arr[i++];
		add_dll(&tokens, new_dll(token));
	}
	return (tokens);
}

static void	build_commands_test(void)
{
	t_unit_test	*unit_test;
	t_dll		*commands;
	t_command	*command;

	init_build_commands_test((t_token[]) {{T_WORD, "ls"}}, 1,
			&unit_test, "build_commands (simple command without arguments)",
			&commands);
	build_commands_basic_tests(commands, 1, (const char *[]){"ls"}, unit_test);
	command = commands->data;
	build_commands_args_tests(command->args, (char *[]) {"ls"}, 1,
		unit_test, "sets command's args to expected args");
	build_commands_fd_tests(command->in_files, (t_file_type[]){FILE_STD}, (char *[]){NULL}, 1,
		unit_test, "sets input files to expected files");
	build_commands_fd_tests(command->out_files, (t_file_type[]){FILE_STD}, (char *[]){NULL}, 1,
		unit_test, "sets output files to expected files");
	clear_dll(&commands, free_command);
	end_unit_test(unit_test);

	init_build_commands_test((t_token[]) {{T_WORD, "ls"},{T_WORD, "-l"},{T_WORD, "."}}, 3,
			&unit_test, "build_commands (simple command with arguments)",
			&commands);
	build_commands_basic_tests(commands, 1, (const char *[]){"ls"}, unit_test);
	command = commands->data;
	build_commands_args_tests(command->args, (char *[]) {"ls", "-l", "."}, 3,
		unit_test, "sets command's args to expected args");
	build_commands_fd_tests(command->in_files, (t_file_type[]){FILE_STD}, (char *[]){NULL}, 1,
		unit_test, "sets input files to expected files");
	build_commands_fd_tests(command->out_files, (t_file_type[]){FILE_STD}, (char *[]){NULL}, 1,
		unit_test, "sets output files to expected files");
	clear_dll(&commands, free_command);
	end_unit_test(unit_test);

	init_build_commands_test((t_token[]) {{T_HEREDOC, "<<"},{T_WORD, "EOF"},{T_REDIR_IN, "<"},{T_WORD, "redir_in"},{T_WORD, "cat"},{T_REDIR_OUT, ">"},{T_WORD, "redir_out"},{T_REDIR_APPEND, ">>"},{T_WORD, "redir_append"}}, 9,
			&unit_test, "build_commands (simple command with redirections)",
			&commands);
	build_commands_basic_tests(commands, 1, (const char *[]){"cat"}, unit_test);
	command = commands->data;
	build_commands_args_tests(command->args, (char *[]) {"cat"}, 1,
		unit_test, "sets command's args to expected args");
	build_commands_fd_tests(command->in_files, (t_file_type[]){FILE_HEREDOC, FILE_REG}, (char *[]){"EOF", "redir_in"}, 2,
		unit_test, "sets input files to expected files");
	build_commands_fd_tests(command->out_files, (t_file_type[]){FILE_REG, FILE_REG}, (char *[]){"redir_out", "redir_append"}, 2,
		unit_test, "sets output files to expected files");
	clear_dll(&commands, free_command);
	end_unit_test(unit_test);

	init_build_commands_test((t_token[]) {{T_WORD, "ls"},{T_PIPE, "|"},{T_WORD, "grep"}}, 3,
			&unit_test, "build_commands (multiple commands)",
			&commands);
	build_commands_basic_tests(commands, 2, (const char *[]){"ls", "grep"}, unit_test);
	command = commands->data;
	build_commands_args_tests(command->args, (char *[]) {"ls"}, 1,
		unit_test, "sets first command's args to expected args");
	build_commands_fd_tests(command->in_files, (t_file_type[]){FILE_STD}, (char *[]){NULL}, 1,
		unit_test, "sets first command's input files to expected files");
	build_commands_fd_tests(command->out_files, (t_file_type[]){FILE_PIPE}, (char *[]){NULL}, 1,
		unit_test, "sets first command's output files to expected files");
	command = commands->next->data;
	build_commands_args_tests(command->args, (char *[]) {"grep"}, 1,
		unit_test, "sets second command's args to expected args");
	build_commands_fd_tests(command->in_files, (t_file_type[]){FILE_PIPE}, (char *[]){NULL}, 1,
		unit_test, "sets second command's input files to expected files");
	build_commands_fd_tests(command->out_files, (t_file_type[]){FILE_STD}, (char *[]){NULL}, 1,
		unit_test, "sets second command's output files to expected files");
	clear_dll(&commands, free_command);
	end_unit_test(unit_test);

	init_build_commands_test((t_token[]) {{T_HEREDOC, "<<"},{T_WORD, "EOF"},{T_WORD, "cat"},{T_WORD, "-e"},{T_WORD, "cat_file"},{T_PIPE, "|"},{T_REDIR_OUT, ">"},{T_WORD, "redir_out"},{T_WORD, "grep"}}, 9,
			&unit_test, "build_commands (multi-commands with redirections)",
			&commands);
	build_commands_basic_tests(commands, 2, (const char *[]){"cat", "grep"}, unit_test);
	command = commands->data;
	build_commands_args_tests(command->args, (char *[]) {"cat", "-e", "cat_file"}, 3,
		unit_test, "sets command's args to expected args");
	build_commands_fd_tests(command->in_files, (t_file_type[]){FILE_HEREDOC}, (char *[]){"EOF"}, 1,
		unit_test, "sets input files to expected files");
	build_commands_fd_tests(command->out_files, (t_file_type[]){FILE_PIPE}, (char *[]){NULL}, 1,
		unit_test, "sets output files to expected files");
	command = commands->next->data;
	build_commands_args_tests(command->args, (char *[]) {"grep"}, 1,
		unit_test, "sets command's args to expected args");
	build_commands_fd_tests(command->in_files, (t_file_type[]){FILE_PIPE}, (char *[]){NULL}, 1,
		unit_test, "sets input files to expected files");
	build_commands_fd_tests(command->out_files, (t_file_type[]){FILE_REG}, (char *[]){"redir_out"}, 1,
		unit_test, "sets output files to expected files");
	clear_dll(&commands, free_command);
	end_unit_test(unit_test);
}

static void	init_build_commands_test(t_token *tokens_arr, size_t size,
				t_unit_test **unit_test_ptr, const char *test,
				t_dll **commands_ptr)
{
	t_dll	*tokens;

	*unit_test_ptr = new_unit_test(test, false);
	tokens = tokens_from_array(tokens_arr, size);
	cut_assert(tokens != NULL, *unit_test_ptr, "tokens initialization succeeds");
	*commands_ptr = build_commands(tokens);
	cut_assert(*commands_ptr != NULL, *unit_test_ptr,
		"returns non-null pointer on list of commands");
}

static void	build_commands_basic_tests(t_dll *commands, size_t expected_size,
				const char **commands_name, t_unit_test *unit_test)
{
	t_command	*command;
	size_t		i;
	size_t		valids;

	cut_expect(dll_size(commands) == expected_size, unit_test,
		"list has expected number of commands");
	valids = 0;
	i = 0;
	while (i < expected_size && commands != NULL)
	{
		command = commands->data;
		valids += strcmp(command->args[0], commands_name[i++]) == 0;
		commands = commands->next;
	}
	cut_expect(valids == i, unit_test, "sets each command's name as first arg");
}

static void	build_commands_args_tests(char **command_args,
				char **expected_args, size_t expected_args_size,
				t_unit_test *unit_test, const char *test)
{
	size_t	i;
	size_t	valids;

	valids = 0;
	i = 0;
	while (command_args[i] != NULL && i < expected_args_size)
	{
		valids += strcmp(command_args[i], expected_args[i]) == 0;
		i++;
	}
	cut_expect(i == expected_args_size && command_args[i] == NULL && i == valids,
		unit_test, test);
}

#include <stdio.h>

static void	build_commands_fd_tests(t_dll *files,
				t_file_type *expected_files_type,
				char **expected_files_path, size_t expected_files_size,
				t_unit_test *unit_test, const char *test)
{
	size_t	i;
	size_t	files_size;
	size_t	valids;

	files_size = dll_size(files);
	valids = 0;
	i = 0;
	while (i < expected_files_size && files != NULL)
	{
		valids += expected_files_type[i] == ((t_file *) files->data)->type
			&& ((expected_files_path[i] == NULL && ((t_file *)files->data)->path == NULL)
			|| strcmp(expected_files_path[i], ((t_file *) files->data)->path) == 0);
		files = files->next;
		i++;
	}
	cut_expect(i == files_size && i == expected_files_size && i == valids,
		unit_test, test);
}
