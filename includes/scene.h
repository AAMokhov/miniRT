
#ifndef SCENE_H
# define SCENE_H

//содержит указатели на лист всех камер, на лист всех фигур, на лист света
typedef struct	s_scene
{
	t_camera 	*cams;
	t_sphere 	*sphere; // нужно убрать
	t_list		**ls_head_fig;
	int			flg_ambl_light;
	int			amlight_color;
	float		ambient_light;
	float 		width;
	float 		height;
}				t_scene;

t_scene	*ft_new_scene(t_camera *cam, t_sphere *sphere);

#endif
