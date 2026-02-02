#include <stdio.h>
#include <stdarg.h>
#include "modules/output.h"

void	cut_output(int fd, const char *style, const char *fmt, ...)
{
	va_list	ap;

	if (fd < 0 || fmt == NULL)
		return ;
	if (style != NULL)
		dprintf(fd, "%s", style); 
	va_start(ap, fmt);
	vdprintf(fd, fmt, ap);
	va_end(ap);
	if (style != NULL)
		dprintf(fd, "%s", CUT_DEFAULT_STYLE);
}
