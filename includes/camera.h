
#ifndef CAMERA_H
# define CAMERA_H

//always == -1 (?why)
typedef struct	s_camera
{
	t_vector	*origin;
	t_vector	*direction;
	float 		fov;

	void		*img_ptr;
	char		*img_adr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_camera;

t_camera	*ft_new_cam(t_vector *origin, t_vector *direction, float fov);

#endif
