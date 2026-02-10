#include "cut.h"
#include "dll.h"
#include "file.h"

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
	t_file		*file;

	unit_test = new_unit_test("new_dll", false);
	file = new_file(NULL, FILE_REG, 0);
	cut_assert(file != NULL, unit_test, "data initialization succeeds");
	dll = new_dll(file);
	cut_assert(dll != NULL, unit_test,
		"returns non-null pointer on dll structure");
	cut_expect(dll->prev == NULL, unit_test,
		"sets dll's previous node to NULL");
	cut_expect(dll->next == NULL, unit_test,
		"sets dll's next node to NULL");
	cut_expect(dll->data == file, unit_test,
		"sets dll node's content to given data");
	free_dll(dll, free_file);
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
	cut_expect(new_node->prev == dll, unit_test,
		"updates new node's previous node");
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

void	dll_last_test(void)
{
	t_unit_test	*unit_test;
	t_dll		*dll;
	t_dll		*new_node;

	unit_test = new_unit_test("dll_last", false);
	dll = NULL;
	cut_expect(dll_last(dll) == NULL, unit_test,
		"returns NULL for empty dll");
	new_node = new_dll(NULL);
	cut_assert(new_node != NULL, unit_test, "new node initialization succeeds");
	add_dll(&dll, new_node);
	cut_expect(dll_last(dll) == new_node, unit_test,
		"returns only node in the dll");
	new_node = new_dll(NULL);
	cut_assert(new_node != NULL, unit_test, "second node initialization succeeds");
	add_dll(&dll, new_node);
	cut_expect(dll_last(dll) == new_node, unit_test,
		"returns last node in the list");
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
	dll_last_test();
	dll_for_each_test();
}
