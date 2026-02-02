#ifndef CUT_H
#define CUT_H

#define CUT_DEFAULT_STYLE			"\x1b[0m"
#define CUT_COLOR_BLACK				"\x1b[30m"
#define CUT_COLOR_RED				"\x1b[31m"
#define CUT_COLOR_GREEN				"\x1b[32m"
#define CUT_COLOR_YELLOW			"\x1b[33m"
#define CUT_COLOR_BLUE				"\x1b[34m"
#define CUT_COLOR_MAGENTA			"\x1b[35m"
#define CUT_COLOR_CYAN				"\x1b[36m"
#define CUT_COLOR_WHITE				"\x1b[37m"
#define CUT_COLOR_GRAY				"\x1b[90m"
#define CUT_COLOR_BRIGHT_RED		"\x1b[91m"
#define CUT_COLOR_BRIGHT_GREEN		"\x1b[92m"
#define CUT_COLOR_BRIGHT_YELLOW		"\x1b[93m"
#define CUT_COLOR_BRIGHT_BLUE		"\x1b[94m"
#define CUT_COLOR_BRIGHT_MAGENTA	"\x1b[95m"
#define CUT_COLOR_BRIGHT_CYAN		"\x1b[96m"
#define CUT_COLOR_BRIGHT_WHITE		"\x1b[97m"

#define CUT_BOLD_BLACK			"\x1b[1;30m"
#define CUT_BOLD_RED			"\x1b[1;31m"
#define CUT_BOLD_GREEN			"\x1b[1;32m"
#define CUT_BOLD_YELLOW			"\x1b[1;33m"
#define CUT_BOLD_BLUE			"\x1b[1;34m"
#define CUT_BOLD_MAGENTA		"\x1b[1;35m"
#define CUT_BOLD_CYAN			"\x1b[1;36m"
#define CUT_BOLD_WHITE			"\x1b[1;37m"
#define CUT_BOLD_GRAY			"\x1b[1;90m"
#define CUT_BOLD_BRIGHT_RED		"\x1b[1;91m"
#define CUT_BOLD_BRIGHT_GREEN	"\x1b[1;92m"
#define CUT_BOLD_BRIGHT_YELLOW	"\x1b[1;93m"
#define CUT_BOLD_BRIGHT_BLUE	"\x1b[1;94m"
#define CUT_BOLD_BRIGHT_MAGENTA	"\x1b[1;95m"
#define CUT_BOLD_BRIGHT_CYAN	"\x1b[1;96m"
#define CUT_BOLD_BRIGHT_WHITE	"\x1b[1;97m"

#define CUT_UNDERLINE_BLACK				"\x1b[4;30m"
#define CUT_UNDERLINE_RED				"\x1b[4;31m"
#define CUT_UNDERLINE_GREEN				"\x1b[4;32m"
#define CUT_UNDERLINE_YELLOW			"\x1b[4;33m"
#define CUT_UNDERLINE_BLUE				"\x1b[4;34m"
#define CUT_UNDERLINE_MAGENTA			"\x1b[4;35m"
#define CUT_UNDERLINE_CYAN				"\x1b[4;36m"
#define CUT_UNDERLINE_WHITE				"\x1b[4;37m"
#define CUT_UNDERLINE_GRAY				"\x1b[4;90m"
#define CUT_UNDERLINE_BRIGHT_RED		"\x1b[4;91m"
#define CUT_UNDERLINE_BRIGHT_GREEN		"\x1b[4;92m"
#define CUT_UNDERLINE_BRIGHT_YELLOW		"\x1b[4;93m"
#define CUT_UNDERLINE_BRIGHT_BLUE		"\x1b[4;94m"
#define CUT_UNDERLINE_BRIGHT_MAGENTA	"\x1b[4;95m"
#define CUT_UNDERLINE_BRIGHT_CYAN		"\x1b[4;96m"
#define CUT_UNDERLINE_BRIGHT_WHITE		"\x1b[4;97m"

#include <stdbool.h>
#include <stddef.h>

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

int	cut_assert(int assertion_result, t_unit_test *unit_test,
		const char *assertion);

int	cut_assert_eq(void *p1, void *p2, size_t size,
		int (*cmp)(void *, void *, size_t),
		t_unit_test *unit_test, const char *assertion);

int	cut_cmp_int(void *i1, void *i2, size_t size);

int	cut_cmp_str(void *s1, void *s2, size_t cmp_len);

int	cut_cmp_ptr(void *p1, void *p2, size_t size);

int cut_cmp_mem(void *m1, void *m2, size_t size);

int	cut_expect(int result, t_unit_test *unit_test, const char *expected);

int	cut_expect_eq(void *p1, void *p2, size_t size,
		int (*cmp)(void *, void *, size_t),
		t_unit_test *unit_test, const char *expected);

void	cut_output(int fd, const char *style, const char *fmt, ...);

t_unit_test	*new_unit_test(const char *name, bool end_on_failure);

void		end_unit_test(t_unit_test *unit_test);

#endif // !CUT_H
