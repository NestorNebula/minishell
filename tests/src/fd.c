#include "cut.h"
#include "fd.h"

void	new_fd_test(void)
{
	t_unit_test	*unit_test;
	t_fd		*fd;

	unit_test = new_unit_test("new_fd", false);
	fd = new_fd(0, FD_SUCCESS);
	cut_assert(fd != NULL, unit_test,
		"returns non-null pointer on fd structure");
	cut_expect(fd->fd == 0, unit_test,
		"stores fd argument as fd");
	cut_expect(fd->status == FD_SUCCESS, unit_test,
		"stores status argument in fd structure");
	free_fd(fd);
	end_unit_test(unit_test);
}

int	main(void)
{
	new_fd_test();
	return (0);
}
