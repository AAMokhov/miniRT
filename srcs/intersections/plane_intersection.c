
#include "minirt.h"

int	ft_pl_intersect(t_camera *cam, t_vector *ray, t_plane *plane)
{
	float		denom;
	float		dist;
	t_vector	*cam_plane;

	(void)cam;
	denom = ft_vec_dotprod(ray, plane->orientation);
	if (!denom)
		return (0);
	cam_plane = ft_vec_subtraction(ray, plane->centre);
	dist = ft_vec_dotprod(cam_plane, plane->centre) / denom;
	free(cam_plane);
	return(dist);
}
