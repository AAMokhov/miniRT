
#ifndef CAMERA_H
# define CAMERA_H

#include "tuple.h"

typedef struct	s_camera
{
	t_point		*origin;
	t_vector	*direction;
	float 		fov;
}				t_camera;

t_camera	*ft_new_cam(t_vector *origin, t_vector *direction, float fov);

#endif
