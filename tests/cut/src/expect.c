#include <unistd.h>
#include "modules/expect.h"
#include "modules/output.h"

static void	handle_result(int result, t_unit_test *unit_test,
				const char *expected);

int	cut_expect(int result, t_unit_test *unit_test, const char *expected)
{
	if (unit_test == NULL || unit_test->status != UT_ONGOING)
		return (0);
	unit_test->tests_count++;
	handle_result(result, unit_test, expected);
	return (result != 0);
}

int	cut_expect_eq(void *p1, void *p2, size_t size,
		int (*cmp)(void *, void *, size_t),
		t_unit_test *unit_test, const char *expected)
{
	int	result;

	if (unit_test == NULL || unit_test->status != UT_ONGOING)
		return (0);
	unit_test->tests_count++;
	result = 0;
	if (cmp != NULL)
		result = cmp(p1, p2, size) == 0;
	handle_result(result, unit_test, expected);
	return (result != 0);
}

static void	handle_result(int result, t_unit_test *unit_test,
				const char *expected)
{
	if (result != 0)
	{
		if (expected != NULL)
			cut_output(STDOUT_FILENO, CUT_COLOR_GREEN, "| %s\n", expected); 
		unit_test->successful_tests++;
	}
	else
	{
		if (expected != NULL)
			cut_output(STDERR_FILENO, CUT_COLOR_RED, "| %s\n", expected);
		if (unit_test->end_on_failure)
			unit_test->status = UT_FAILURE;
	}
}
