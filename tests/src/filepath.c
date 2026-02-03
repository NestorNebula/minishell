#include <stdlib.h>
#include <string.h>
#include "cut.h"
#include "filepath.h"

static void	find_filepath_valid_filename_test(const char *filename,
				const char *expected_filepath, const char *test);

static void	find_filepath_invalid_filename_test(const char *filename,
				const char *test);

int	main(void)
{
	find_filepath_valid_filename_test("cat", "/usr/bin/cat",
		"find_filepath (works for valid command \"cat\")");
	find_filepath_valid_filename_test("yes", "/usr/bin/yes",
		"find_filepath (works for valid command \"yes\")");
	find_filepath_invalid_filename_test("/usr/bin/cat",
		"find_filepath (doesn't create filepath when given an absolute path)");
	find_filepath_invalid_filename_test("./cat",
		"find_filepath (doesn't create filepath when given a relative path)");
	find_filepath_invalid_filename_test("cats",
		"find_filepath (doesn't create filepath for invalid command");
	find_filepath_invalid_filename_test(" ",
		"find_filepath (doesn't create filepath for invalid string)");
	find_filepath_invalid_filename_test("",
		"find_filepath (doesn't create filepath for empty string)");
	find_filepath_invalid_filename_test(NULL,
		"find_filepath (doesn't create filepath for NULL string)");
	return (0);
}

static void	find_filepath_valid_filename_test(const char *filename,
				const char *expected_filepath, const char *test)
{
	t_unit_test	*unit_test;
	char		*filepath;

	unit_test = new_unit_test(test, false);
	filepath = find_filepath(filename);
	cut_assert(filepath != NULL, unit_test, "returns a non-null filepath");
	cut_expect(strcmp(filepath, expected_filepath) == 0, unit_test,
		"returns the expected filepath");
	free(filepath);
	end_unit_test(unit_test);
}

static void	find_filepath_invalid_filename_test(const char *filename,
				const char *test)
{
	t_unit_test	*unit_test;
	char		*filepath;

	unit_test = new_unit_test(test, false);
	filepath = find_filepath(filename);
	cut_assert(filepath == NULL, unit_test, "returns NULL filepath");
	end_unit_test(unit_test);
}
