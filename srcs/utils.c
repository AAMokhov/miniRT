
#include "minirt.h"

void	ft_error_exit(int code)
{
	if (code == -1)
		write(STDERR_FILENO,
			  "Error: Can't allocate memory for new element\n", 46);
	exit(code);
}