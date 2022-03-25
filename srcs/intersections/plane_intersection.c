
#include "minirt.h"

t_pair	ft_pl_intersect(void *is_ray, void *is_plane)
{
	// t_vector	*origin_to_centre;
	// t_camera	*cam;
	// t_ray		*ray;
	// t_figures	*plane;
	// float		denom;
	// float		nom;

	// cam = (t_camera *)is_cam;
	// ray = (t_ray *)is_ray;
	// plane = (t_figures *)is_plane;

	// denom = ft_vec_dotprod(plane->normal, &(ray->direction));
	// origin_to_centre = ft_vec_subtract(plane->fig.pl.centre, cam->origin);
	// nom = ft_vec_dotprod(origin_to_centre, plane->normal);
	// free(origin_to_centre);
	// if (denom > 0.000001)
	// {
	// 	if ((-nom /denom) > 0.000001)
	// 		return ((t_pair){-nom /denom, 0});
	// }
	// return((t_pair){0, 0});
	t_figures	*plane;
	t_ray 		*r;
	t_vector	*origin_to_center;
	t_vector	*orientation;
	float		a;
	float		b;

	plane = (t_figures *)is_plane;
	r = (t_ray *)is_ray;

	origin_to_center = ft_vec_subtract(&(r->origin), plane->fig.pl.centre);
	orientation = plane->normal;
	b = ft_vec_dotprod(orientation, &(r->direction));
	if (b < 0)
	{
		orientation = multiply_on_scalar(plane->normal, -1);
		b = ft_vec_dotprod(orientation, &(r->direction));
	}
	a = ft_vec_dotprod(orientation, origin_to_center);
	if (b != 0 && ((a > 0 && b < 0) || (a < 0 && b > 0)))
		return ((t_pair){-a/b, FLT_MAX});
	return ((t_pair){FLT_MAX, FLT_MAX});
}
