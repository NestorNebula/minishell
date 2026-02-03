#include "cut.h"
#include "dll.h"
#include "fd.h"

#define SIZE 10

int	count = 0;

void	f(void *data)
{
	(void) data;
	count++;
}

void	new_dll_test(void)
{
	t_unit_test	*unit_test;
	t_dll		*dll;
	t_fd		*fd;

	unit_test = new_unit_test("new_dll", false);
	fd = new_fd(0, 0);
	cut_assert(fd != NULL, unit_test, "data initialization succeeds");
	dll = new_dll(fd);
	cut_assert(dll != NULL, unit_test,
		"returns non-null pointer on dll structure");
	cut_expect(dll->data == fd, unit_test,
		"sets dll node's content to given data");
	free_dll(dll, free_fd);
	end_unit_test(unit_test);
}

void	add_dll_test(void)
{
	t_unit_test	*unit_test;
	t_dll		*dll;
	t_dll		*new_node;

	unit_test = new_unit_test("add_dll", false);
	dll = new_dll(NULL);
	cut_assert(dll != NULL, unit_test, "dll initialization succeeds");
	new_node = new_dll(NULL);
	cut_assert(new_node != NULL, unit_test, "new node initialization succeeds");
	add_dll(&dll, new_node);
	cut_expect(dll->next == new_node, unit_test, "adds new node to end of dll");
	clear_dll(&dll, NULL);
	end_unit_test(unit_test);
}

void	dll_size_test(void)
{
	t_unit_test	*unit_test;
	t_dll		*dll;
	int			i;

	unit_test = new_unit_test("dll_size", false);
	dll = NULL;
	cut_expect(dll_size(dll) == 0, unit_test, "returns 0 on empty dll");
	i = 0;
	while (i < SIZE)
	{
		add_dll(&dll, new_dll(NULL));
		i++;
	}
	cut_expect(dll_size(dll) == SIZE, unit_test, "returns size of dll");
	clear_dll(&dll, NULL);
	end_unit_test(unit_test);
}

void	dll_for_each_test(void)
{
	t_unit_test	*unit_test;
	t_dll		*dll;
	int			i;

	unit_test = new_unit_test("dll_for_each", false);
	i = 0;
	dll = NULL;
	while (i < SIZE)
	{
		add_dll(&dll, new_dll(NULL));
		i++;
	}
	dll_for_each(dll, &f);
	cut_expect(count == SIZE, unit_test, "calls f for each node in dll");
	clear_dll(&dll, NULL);
	end_unit_test(unit_test);
}

int	main(void)
{
	new_dll_test();
	add_dll_test();
	dll_size_test();
	dll_for_each_test();
}
