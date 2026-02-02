#if !defined CUT_UNIT_TEST_H && !defined CUT_H
#define CUT_UNIT_TEST_H

#include <stdbool.h>

typedef enum e_unit_test_status {
	UT_ONGOING,
	UT_DONE,
	UT_FAILURE,
	UT_ABORT
}				t_unit_test_status;

typedef struct s_unit_test {
	const char			*name;
	unsigned int		tests_count;
	unsigned int		successful_tests;
	t_unit_test_status	status;
	bool				end_on_failure;
}				t_unit_test;

/**
 * Inits a new unit test structure.
 *
 * @param name The unit test's name
 * @param end_on_failure If true, the first test that fails will
 * end the current unit test. Else, the following tests will still be executed
 * @return A pointer to a unit test structure
 */
t_unit_test	*new_unit_test(const char *name, bool end_on_failure);

/**
 * Displays the unit test's result and frees its content.
 *
 * @param unit_test A pointer to a unit test structure
 */
void		end_unit_test(t_unit_test *unit_test);

#endif // !CUT_UNIT_TEST_H
