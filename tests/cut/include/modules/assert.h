#if !defined CUT_ASSERT_H && !defined CUT_H
#define CUT_ASSERT_H

#include "compare.h"
#include "unit-test.h"

/**
 * Checks that an assertion is true and updates the content
 * of the given unit test accordingly.
 * If the assertion is wrong, exits the program.
 *
 * @param assertion_result The result of the assertion.
 * The assertion will be considered "true" if the result is non-zero
 * @param unit_test The unit test that will be updated based on the
 * assertion result
 * @param assertion A string describing the assertion, that will be printed
 * after the assertion's processing. If NULL, nothing will be printed
 * @return Always returns 1
 */
int	cut_assert(int assertion_result, t_unit_test *unit_test,
		const char *assertion);

/**
 * Checks that two values are equal and updates the content
 * of the given unit test accordingly.
 * If the values aren't equal, exits the program.
 *
 * @param p1 A pointer to the first value to compare
 * (or the value itself if the comparison is between two pointers)
 * @param p2 A pointer to the second value to compare
 * (or the value itself if the comparison is between two pointers)
 * @param size The size of the two values to compare
 * @param cmp A pointer to a comparison function that returns 0 if
 * the two values are equal and a non-zero value otherwise.
 * @param unit_test The unit test that will be updated based on the
 * comparison function's return value
 * @param assertion A string describing the comparison's assertion,
 * that will be printed after the assertion's processing.
 * If NULL, nothing will be printed
 * @return Always returns 1
 */
int	cut_assert_eq(void *p1, void *p2, size_t size,
		int (*cmp)(void *, void *, size_t),
		t_unit_test *unit_test, const char *assertion);

#endif // !CUT_ASSERT_H
