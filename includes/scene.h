
#ifndef SCENE_H
# define SCENE_H

typedef struct		s_light
{
	t_vector		*origin;
	float			br;
	int				color;
}					t_light;

//содержит указатели на лист всех камер, на лист всех фигур, на лист света
typedef struct	s_scene
{
	t_sphere 	*sphere; // нужно убрать
	t_camera 	*cams;
	t_list		*ls_head_fig;
	t_light		*light;
	int			flg_ambl_light;
	int			amlight_color;
	float		ambient_light;
	float 		width;
	float 		height;
}				t_scene;

t_scene	*ft_new_scene(t_camera *cam, t_sphere *sphere);

#endif
