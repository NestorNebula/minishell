#include <string.h>
#include "cut.h"
#include "env.h"

#define KEY "key"
#define VALUE "value"

void	new_env_var_test(void)
{
	t_unit_test	*unit_test;
	t_env_var	*env_var;

	unit_test = new_unit_test("new_env_var", false);
	env_var = new_env_var(KEY, VALUE);
	cut_assert(env_var != NULL, unit_test,
		"returns non-null pointer to env_var structure");
	cut_expect(strcmp(env_var->key, KEY) == 0, unit_test,
		"stores given key in env_var structure");
	cut_expect(strcmp(env_var->value, VALUE) == 0, unit_test,
		"stores given value in env_var structure");
	free_env_var(env_var);
	end_unit_test(unit_test);
}

void	find_env_var_test(void)
{

	t_unit_test	*unit_test;
	t_dll		*env_vars;
	t_env_var	*env_var;
	t_env_var	*found;

	unit_test = new_unit_test("find_env_var", false);
	env_var = new_env_var(KEY, VALUE);
	cut_assert(env_var != NULL, unit_test,
		"env_var initialization works correctly");
	env_vars = NULL;
	add_dll(&env_vars, new_dll(env_var));
	cut_assert(env_vars != NULL, unit_test,
		"adds env_var to list properly");
	found = find_env_var(env_vars, KEY);
	cut_assert(found != NULL, unit_test,
		"returns non-null pointer to env_var structure when given existing key");
	cut_expect(strcmp(found->value, VALUE) == 0, unit_test,
		"returns pointer to the env_var structure with the corresponding key");
	found = find_env_var(env_vars, VALUE);
	cut_expect(found == NULL, unit_test,
		"returns null pointer when given non-existent key");
	clear_dll(&env_vars, free_env_var);
	end_unit_test(unit_test);
}

int	main(void)
{
	new_env_var_test();
	find_env_var_test();
}
