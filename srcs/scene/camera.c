#include "minirt.h"

t_camera	*ft_new_cam(t_vector *origin, t_vector *direction, float fov)
{
	t_camera	*cam;
	cam = malloc(sizeof(t_camera));
	if (!cam)
		ft_error_exit(-1);
	cam->origin = origin;
	cam->direction = direction;
	cam->fov = fov;
	return (cam);
}
