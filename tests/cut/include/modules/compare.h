#if !defined CUT_COMPARE_H && !defined CUT_H
#define CUT_COMPARE_H

#include <stddef.h>

/**
 * Compares two integers.
 *
 * @param i1 A pointer to the first integer to compare
 * @param i2 A pointer to the second integer to compare
 * @param size The number of bytes taken by an integer
 * @return The difference between i1 and i2
 */
int	cut_cmp_int(void *i1, void *i2, size_t size);

/**
 * Compares two strings.
 *
 * @param s1 A pointer to the first character of the first string to compare
 * @param s2 A pointer to the first character of the second string to compare
 * @param cmp_len The number of characters to compare
 * @return 0 if the strings are equal after reaching the end of the string or
 * having compared the given number of characters.
 * The difference between the first two characters that don't match otherwise
 */
int	cut_cmp_str(void *s1, void *s2, size_t cmp_len);

/**
 * Compares two pointers
 *
 * @param p1 The first pointer to compare
 * @param p2 The second pointer to compare
 * @param size The number of bytes taken by a pointer
 * @return The difference between p1 and p2
 */
int	cut_cmp_ptr(void *p1, void *p2, size_t size);

/**
 * Compares two chunks of memory.
 *
 * @param m1 A pointer to the first chunk of memory to compare
 * @param m2 A pointer to the second chunk of memory to compare
 * @param size The number of bytes to compare between the two chunks
 * @return 0 if the two chunks are equal.
 * The difference between the first two bytes that aren't equal otherwise
 */
int cut_cmp_mem(void *m1, void *m2, size_t size);

#endif // !CUT_COMPARE_H
