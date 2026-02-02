#include <string.h>

int	cut_cmp_int(void *i1, void *i2, size_t size)
{
	return (memcmp(i1, i2, size));
}

int	cut_cmp_str(void *s1, void *s2, size_t cmp_len)
{
	return (strncmp(s1, s2, cmp_len));
}

int	cut_cmp_ptr(void *p1, void *p2, size_t size)
{
	return (memcmp(&p1, &p2, size));
}

int cut_cmp_mem(void *m1, void *m2, size_t size)
{
	return (memcmp(m1, m2, size));
}
