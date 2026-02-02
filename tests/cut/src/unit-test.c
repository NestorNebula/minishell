#include <stdlib.h>
#include <unistd.h>
#include "modules/unit-test.h"
#include "modules/output.h"

t_unit_test	*new_unit_test(const char *name, bool end_on_failure)
{
	t_unit_test	*unit_test;

	if (name == NULL)
		name = "C Unit Test";
	cut_output(STDOUT_FILENO, CUT_BOLD_BRIGHT_WHITE, "\n[UNIT TEST] %s\n", name);
	unit_test = malloc(sizeof(t_unit_test));
	if (unit_test == NULL)
	{
		cut_output(STDERR_FILENO, CUT_COLOR_RED,
			"Error during test setup, exiting program...\n");
		exit(EXIT_FAILURE);
	}
	unit_test->name = name;
	unit_test->tests_count = 0;
	unit_test->successful_tests = 0;
	unit_test->status = UT_ONGOING;
	unit_test->end_on_failure = end_on_failure;
	return (unit_test);
}

void		end_unit_test(t_unit_test *unit_test)
{
	if (unit_test == NULL)
		return ;
	unit_test->status = UT_DONE;
	if (unit_test->tests_count == unit_test->successful_tests
		&& unit_test->tests_count != 0)
		cut_output(STDOUT_FILENO, CUT_BOLD_GREEN,
			"%s succeeded with 100%% (%u/%u) successful tests\n",
			unit_test->name, unit_test->successful_tests, unit_test->tests_count);
	else if (unit_test->tests_count != 0)
		cut_output(STDOUT_FILENO, CUT_BOLD_RED,
			"%s failed with %.2f%% (%u/%u) successful tests\n",
			unit_test->name,
			(double) unit_test->successful_tests / unit_test->tests_count * 100,
			unit_test->successful_tests, unit_test->tests_count); 
	else
		cut_output(STDOUT_FILENO, CUT_BOLD_GRAY,"%s ended before doing any test\n");
	free(unit_test);
}
