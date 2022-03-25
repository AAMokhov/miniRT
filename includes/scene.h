
#ifndef SCENE_H
# define SCENE_H

# include "matrix.h"
# include "tuple.h"

typedef struct		s_light
{
	t_vector		*origin;
	float			br;
	t_color				color;
}					t_light;

typedef struct		s_image
{
	void		*img_ptr;
	char		*img_adr;

	int			bits_per_pixel;
	int			line_length;
	int			endian;

	int			h;
	int			w;
}					t_image;

typedef struct	s_vplane
{
	float		width;
	float		height;

	float 		x_pixel; //пиксель окна просмотра
	float 		y_pixel;

	float 		rotation_x;
	float 		rotation_y;

	t_matrix*	transform;
	t_matrix*	rotate;
}				t_vplane;

//содержит указатели на лист всех камер, на лист всех фигур, на лист света
typedef struct	s_scene_attr
{
	void		*mlx_ptr;
	void		*win_ptr;

	t_camera 	*cams;
	t_list		*ls_head_fig;
	t_light		*light;
	t_image		canvas;
	t_vplane	*vplane;

	int			flg_ambl_light;
	t_color		amlight_color;
	float		ambient_light;
	float 		width;
	float 		height;
}				t_scene;

t_scene	*ft_new_scene(t_camera *cam);
int		ft_get_view_plane(t_scene *scene);

#endif
