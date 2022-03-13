#include "minirt.h"

void ft_ray_tracing(void *mlx, void *window, t_scene *scene)
{
	int			mlx_x;
	int			mlx_y; //for mlx_pixel_put - заменить на mlx_image
	float		x_angle;
	float 		y_angle;
	int 		color;
	float 		y_ray; //  координаты луча
	float 		x_ray;
	t_vector	*ray;
	t_vplane	*vplane;

	mlx_y = 0;
	vplane = ft_get_view_plane(scene->width, scene->height, scene->cams->fov); //создаем окно прсомотра
	y_angle = (scene->height / 2);
	while (y_angle >= (scene->height / 2) * (-1))
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = (scene->width / 2) * (-1);
		mlx_x = 0;
		while (x_angle <= scene->width / 2)
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = ft_new_vec(x_ray, y_ray, -1);
			ft_vec_normalize(ray); //нормализация не всегда нужна???
			//функция пересечения со сферой
			if (ft_sph_intersect(scene->cams, ray, scene->sphere))
				color = 16777215; //цвета должны преобразовываться в один int
			else
				color = 0;
			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);
			free (ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}

t_vplane	*ft_get_view_plane(float width, float height, float fov)
{
	t_vplane	*vplane;
	float 		aspect_ratio; //масштабирование

	(void)fov;
	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		ft_error_exit(-1);
	aspect_ratio = width / height;
	vplane->width = (tan(fov / 2 * (M_PI / 180))) * 2;
	vplane->height = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width;
	vplane->y_pixel = vplane->height / height;
	return (vplane);
}