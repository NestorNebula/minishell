#include "command.h"
#include "cut.h"

void	new_command_test(void)
{
	t_unit_test	*unit_test;
	t_command	*command;

	unit_test = new_unit_test("new_command", false);
	command = new_command(NULL);
	cut_assert(command != NULL, unit_test,
		"returns a pointer to a non-null command structure");
	cut_expect(command->raw_argv == NULL, unit_test,
		"sets command's raw_argv to given argument");
	cut_expect(command->args == NULL, unit_test,
		"sets command's args to NULL");
	cut_expect(command->filepath == NULL, unit_test,
		"sets command's filepath to NULL");
	cut_expect(command->pid == -1, unit_test,
		"sets command's pid to -1");
	cut_expect(command->wstatus == -1, unit_test,
		"sets command's wstatus to -1");
	cut_expect(command->in_files == NULL, unit_test,
		"sets command's in_fds to NULL");
	cut_expect(command->out_files == NULL, unit_test,
		"sets command's out_fds to NULL");
	free_command(command);
	end_unit_test(unit_test);
}

int	main(void)
{
	new_command_test();
	return (0);
}
