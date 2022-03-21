#include "minirt.h"

t_scene	*ft_new_scene(t_camera *cam)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		ft_error_exit(-1);
	scene->cams = cam;
	scene->width = 0;
	scene->height = 0;
	return (scene);
}

