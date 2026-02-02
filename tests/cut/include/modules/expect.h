#if !defined CUT_EXPECT_H && !defined CUT_H
#define CUT_EXPECT_H

#include "compare.h"
#include "unit-test.h"

/**
 * Checks that an expected value is true and updates the content
 * of the given unit test accordingly.
 *
 * @param result The result of what was expected.
 * The result will be considered "true" if it is non-zero.
 * @param unit_test The unit test that will be updated based on the result
 * @param expected A string describing what was expected, that will be printed
 * after the result's processing. If NULL, nothing will be printed
 * @return Returns 1 if the result was true, 0 otherwise
 */
int	cut_expect(int result, t_unit_test *unit_test, const char *expected);

/**
 * Checks that two values are equal and updates the content
 * of the given unit test accordingly.
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
 * @param expected A string describing the comparison's expected value,
 * that will be printed after the result's processing.
 * If NULL, nothing will be printed
 * @return Returnsn 1 if the two values were equal, 0 otherwise
 */
int	cut_expect_eq(void *p1, void *p2, size_t size,
		int (*cmp)(void *, void *, size_t),
		t_unit_test *unit_test, const char *expected);

#endif // !CUT_EXPECT_H
