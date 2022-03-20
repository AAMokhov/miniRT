#include "minirt.h"

int	ft_cy_intersect(t_camera *cam, t_vector *ray, t_figures	*cylinder)
{
	float	denom;
	float	dist;
	t_vector	*tmp_vec;

	denom = ft_vec_dotprod(cylinder->normal, ray);
	if (denom < 0)
	{
		ft_vec_mult(cylinder->normal, -1);
		denom *= -1;
	}
	if (denom > 0.000001)
	{
		tmp_vec = ft_vec_subtraction(cylinder->fig.cy.centre, cam->origin);
		dist = ft_vec_dotprod(tmp_vec, cylinder->normal) / denom;
		if (dist >= 0.000001)
		{
			free(tmp_vec);
			return (dist);
		}
		free(tmp_vec);
	}
	return(0);
}

