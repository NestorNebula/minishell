#include "cut.h"
#include "stack.h"

#define STACK_SIZE 10
#define STACK_TEST_LOOPS 5

static void	test_new_stack(void);

static void	test_stack_shift(void);

static void	test_stack_pop(void);

static void	test_stack_reduce(void);

int	main(void)
{
	test_new_stack();
	test_stack_shift();
	test_stack_pop();
	test_stack_reduce();
}

static void	test_new_stack(void)
{
	t_unit_test	*unit_test;
	t_stack		*stack;

	unit_test = new_unit_test("new_stack", false);
	stack = new_stack(STACK_SIZE);
	cut_assert(stack != NULL, unit_test,
		"returns non-null pointer to stack structure");
	cut_expect(stack->content != NULL, unit_test,
		"initializes stack's content array");
	cut_expect(stack->len == 0, unit_test,
		"sets stack's length to 0");
	cut_expect(stack->size == STACK_SIZE, unit_test,
		"sets stack's size to the given size");
	free_stack(stack);
	stack = new_stack(0);
	cut_assert(stack != NULL, unit_test,
		"stack initialization succeeds");
	cut_expect(stack->size == DEFAULT_STACK_SIZE, unit_test,
		"sets stack's size to default when given 0 as stack size");
	free_stack(stack);
	end_unit_test(unit_test);
}

static void	test_stack_shift(void)
{
	t_unit_test	*unit_test;
	t_stack		*stack;
	int			i;

	unit_test = new_unit_test("stack_shift", false);
	stack = new_stack(STACK_SIZE);
	cut_assert(stack != NULL, unit_test,
		"stack initialization succeeds");
	i = 1;
	while (i <= STACK_TEST_LOOPS)
	{
		stack_shift(stack, i);
		cut_expect(stack->len == (size_t) i, unit_test,
		"updates stack's length after function call");
		cut_expect(stack->content[stack->len - 1] == i, unit_test,
		"puts given number at the top of the stack");
		i++;
	}
	free_stack(stack);
	end_unit_test(unit_test);
}

static void	test_stack_pop(void)
{
	t_unit_test	*unit_test;
	t_stack		*stack;
	int			i;
	int			n;

	unit_test = new_unit_test("stack_pop", false);
	stack = new_stack(STACK_SIZE);
	cut_assert(stack != NULL, unit_test,
		"stack initialization succeeds");
	i = 1;
	while (i <= STACK_TEST_LOOPS)
		stack_shift(stack, i++);
	i--;
	while (i > 0)
	{
		n = stack_pop(stack);
		cut_expect(n == i, unit_test,
			"removes element on top of the stack");
		cut_expect(stack->len == (size_t) --i, unit_test,
			"updates stack's length after removing an element");
	}
	free_stack(stack);
	end_unit_test(unit_test);
}

static void	test_stack_reduce(void)
{
	t_unit_test	*unit_test;
	t_stack		*stack;
	int			i;
	size_t		previous_len;

	unit_test = new_unit_test("stack_reduce", false);
	stack = new_stack(STACK_SIZE);
	cut_assert(stack != NULL, unit_test,
		"stack initialization succeeds");
	i = 1;
	while (i <= STACK_TEST_LOOPS)
		stack_shift(stack, i++);
	stack_reduce(stack, 1, i);
	cut_expect(stack->len == STACK_TEST_LOOPS, unit_test,
		"lets stack's length unchanged when given 1 "
		"as the number of elements to remove");
	cut_expect(stack->content[stack->len - 1] == i, unit_test,
		"puts new element on top of the stack");
	previous_len = stack->len;
	stack_reduce(stack, 0, i - 1);
	cut_expect(stack->len == previous_len + 1, unit_test,
		"increase stack's length by 1 when given 0 "
		"as the number of elements to remove");
	cut_expect(stack->content[stack->len - 1] == i - 1, unit_test,
		"puts new element on top of the stack");
	previous_len = stack->len;
	stack_reduce(stack, 3, -3);
	cut_expect(stack->len == previous_len - 2, unit_test,
		"updates stack's length correctly when given STACK_LEN > x > 1 "
		"as the number of elements to remove");
	cut_expect(stack->content[stack->len - 1] == -3, unit_test,
		"puts new element on top of the stack");
	stack_reduce(stack, STACK_SIZE, 0);
	cut_expect(stack->len == 1, unit_test,
		"sets stack's length to 1 when given x > STACK_LEN "
		"as the number of elements to remove");
	cut_expect(stack->content[stack->len - 1] == 0, unit_test,
		"puts new element on top of the stack");
	free_stack(stack);
	end_unit_test(unit_test);
}
