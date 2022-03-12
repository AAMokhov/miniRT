
#ifndef CAMERA_H
# define CAMERA_H

//always == -1 (?why)
typedef struct	s_camera
{
	t_vector	*origin;
	t_vector	*direction;
	float 		fov;
}				t_camera;

t_camera	*ft_new_cam(t_vector *origin, t_vector *direction, float fov);

#endif
