#include <fcntl.h>
#include <string.h>
#include "cut.h"
#include "file.h"

#define PATH "path"
#define FLAGS O_RDONLY

void	new_file_test(void)
{
	t_unit_test	*unit_test;
	t_file		*file;

	unit_test = new_unit_test("new_file", false);
	file = new_file(PATH, FILE_REG, FLAGS);
	cut_assert(file != NULL, unit_test,
		"returns non-null pointer on file structure");
	cut_expect(file->path != NULL && strcmp(file->path, PATH) == 0, unit_test,
		"stores path argument as file's path");
	cut_expect(file->flags == FLAGS, unit_test,
		"stores flags argument as file's flags");
	cut_expect(file->status == FILE_DEF, unit_test,
		"sets file's status to default");
	cut_expect(file->type == FILE_REG, unit_test,
		"stores type argument as file's type ");
	free_file(file);
	end_unit_test(unit_test);
}

int	main(void)
{
	new_file_test();
	return (0);
}
