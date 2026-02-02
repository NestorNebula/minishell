#include <stdlib.h>
#include "modules/expect.h"

int	cut_assert(int assertion_result, t_unit_test *unit_test,
		const char *assertion)
{
	if (unit_test == NULL)
		return (1);
	cut_expect(assertion_result, unit_test, assertion);
	if (assertion_result == 0)
	{
		unit_test->status = UT_ABORT;
		end_unit_test(unit_test);
		exit(EXIT_FAILURE);
	}
	return (1);
}

int	cut_assert_eq(void *p1, void *p2, size_t size,
		int (*cmp)(void *, void *, size_t),
		t_unit_test *unit_test, const char *assertion)
{
	int	result;

	if (unit_test == NULL)
		return (1);
	result = cut_expect_eq(p1, p2, size, cmp, unit_test, assertion);
	if (result == 0)
	{
		unit_test->status = UT_ABORT;
		end_unit_test(unit_test);
		exit(EXIT_FAILURE);
	}
	return (1);
}
