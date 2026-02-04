#include <string.h>
#include "cut.h"
#include "file.h"

#define PATH "path"

void	new_file_test(void)
{
	t_unit_test	*unit_test;
	t_file		*file;

	unit_test = new_unit_test("new_file", false);
	file = new_file(PATH, 0, FILE_DEFAULT);
	cut_assert(file != NULL, unit_test,
		"returns non-null pointer on file structure");
	cut_expect(strcmp(file->path, PATH) == 0, unit_test,
		"stores path argument as file's path");
	cut_expect(file->fd == 0, unit_test,
		"stores fd argument as file's fd");
	cut_expect(file->status == FILE_DEFAULT, unit_test,
		"stores status argument as file's status");
	free_file(file);
	end_unit_test(unit_test);
}

int	main(void)
{
	new_file_test();
	return (0);
}
