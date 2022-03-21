#include "minirt.h"

t_sphere	*ft_new_sphere(t_vector *centre, float	radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		ft_error_exit(-1);
	sphere->centre = centre;
	sphere->radius = radius;
	return (sphere);
}