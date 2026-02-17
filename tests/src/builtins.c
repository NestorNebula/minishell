#include "builtins.h"
#include "cut.h"

static void	get_builtin_test(void);

int	main(void)
{
	get_builtin_test();
	return (0);
}

static void	get_builtin_test(void)
{
	t_unit_test		*unit_test;
	t_builtin_fn	builtin;

	unit_test = new_unit_test("get_builtin", false);
	builtin = get_builtin("echo");
	cut_expect(builtin != NULL, unit_test,
		"returns non-null pointer to builtin command's function for echo");
	builtin = get_builtin("cd");
	cut_expect(builtin != NULL, unit_test,
		"returns non-null pointer to builtin command's function for cd");
	builtin = get_builtin("pwd");
	cut_expect(builtin != NULL, unit_test,
		"returns non-null pointer to builtin command's function for pwd");
	builtin = get_builtin("export");
	cut_expect(builtin != NULL, unit_test,
		"returns non-null pointer to builtin command's function for export");
	builtin = get_builtin("unset");
	cut_expect(builtin != NULL, unit_test,
		"returns non-null pointer to builtin command's function for unset");
	builtin = get_builtin("env");
	cut_expect(builtin != NULL, unit_test,
		"returns non-null pointer to builtin command's function for env");
	builtin = get_builtin("exit");
	cut_expect(builtin != NULL, unit_test,
		"returns non-null pointer to builtin command's function for exit");
	builtin = get_builtin("ls");
	cut_expect(builtin == NULL, unit_test,
		"returns null pointer for non-builtin command");
	builtin = get_builtin("cats");
	cut_expect(builtin == NULL, unit_test,
		"returns null pointer for non-existent command");
	end_unit_test(unit_test);
}
