
#include "minirt.h"

void	ft_error_exit(int code)
{
	if (code == -1)
		write(STDERR_FILENO,
			  "Error: Can't allocate memory for new element\n", 46);
	else if (code == -2)
		write(STDERR_FILENO, \
				"Error: Invalid aruments\n", 25);
	exit(code);
}

void		*enh_malloc(unsigned int size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		fatal("in malloc() on memory allocation");
	return (ptr);
}

void		scene_error(char *message)
{
	char error_message[100];

	ft_strcpy(error_message, "Scene Error: ");
	ft_strncat(error_message, message, 87);
	ft_putstr_fd(error_message, 2);
	exit(EXIT_FAILURE);
}

void		fatal(char *message)
{
	char error_message[100];

	ft_strcpy(error_message, "[!!] Fatal Error ");
	ft_strncat(error_message, message, 83);
	perror(error_message);
	exit(EXIT_FAILURE);
}

int			close_program(void *param)
{
	param = (void *)param;
	exit(EXIT_SUCCESS);
	return (1);
}

void		ft_mlx_pixel_put(t_camera *cam, int x, int y, int color)
{
	char	*dst;

	dst = cam->img_adr + (y * cam->line_length + x * (cam->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
