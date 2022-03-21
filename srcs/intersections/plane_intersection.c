
#include "minirt.h"

int	ft_pl_intersect(t_camera *cam, t_vector *ray, t_figures	*plane)
{
	float	denom;
	float	nom;
	float	t;
	t_vector	*tmp_vec;

	denom = ft_vec_dotprod(plane->normal, ray);
	tmp_vec = ft_vec_subtraction(plane->fig.pl.p, cam->origin);
	nom = ft_vec_dotprod(tmp_vec, plane->normal);
	free(tmp_vec);
	if (denom > 0.000001)
	{
		t = -nom /denom;
		if (t > 0.000001)
			return (t);
	}
	return(0);
}
