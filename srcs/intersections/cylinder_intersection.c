#include "minirt.h"

//typedef struct	s_cylinder
//{
//	t_vector	*centre;
//	float		radius;
//	float		height;
//	float		dist1;
//	float		dist2;
//	float		squared_radius;
//}				t_cylinder;

//int					type;
//union u_figures		fig;
//t_color				color;
//t_vector			*normal;
//float				reflective;


float closest_point_on_cylinder(t_figures *cy, t_ray *ray, float t1,
									 float t2)
{
	t_vector *or_to_centre;
	float m1;
	float m2;

	or_to_centre = ft_vec_subtract(&ray->origin,
								cy->fig.cy.centre);

	m1 = ft_vec_dotprod(&ray->direction, cy->normal) * t1;
	m1 += ft_vec_dotprod(or_to_centre, cy->normal);

	m2 = ft_vec_dotprod(&ray->direction, cy->normal) * t2;
	m2 += ft_vec_dotprod(or_to_centre, cy->normal);

	if (m1 > -cy->fig.cy.height / 2 && m1 < cy->fig.cy.height / 2)
	{
		if (m2 > -cy->fig.cy.height / 2 && m2 < cy->fig.cy.height / 2 && m1 >
		        m2)
			m1 = m2;
	}
	else if (m2 > -cy->fig.cy.height / 2 && m2 < cy->fig.cy.height / 2
			 && m1 < -cy->fig.cy.height / 2)
		m1 = m2;
	else
		m1 = MAXFLOAT;
	return (m1);
}

t_pair	ft_cy_intersect(void *is_ray, void	*is_cylinder)
{
	t_vector	*origin_to_center;
	t_figures	*cylinder;
	t_ray 		*r;
	t_pair		roots;
	float		a;
	float		b;
	float		c;

	cylinder = (t_figures *)is_cylinder;
	r = (t_ray *)is_ray;
	origin_to_center = ft_vec_subtract(&(r->origin), cylinder->fig.cy.centre);
	ft_vec_normalize(cylinder->normal);

	a = r->dot_direction - powf(ft_vec_dotprod(&r->direction,
												cylinder->normal), 2);
	b = 2 * (ft_vec_dotprod(&r->direction, origin_to_center)
					- ft_vec_dotprod(&r->direction, cylinder->normal)
					  * ft_vec_dotprod(origin_to_center, cylinder->normal));
	c = ft_vec_dotprod(origin_to_center, origin_to_center)
			   - powf(ft_vec_dotprod(origin_to_center, cylinder->normal), 2)
			   - powf(cylinder->fig.cy.radius, 2);
	roots = ft_quadratic_roots(a, b, c);
	if (roots.x == MAXFLOAT)
		return (roots);
	if (closest_point_on_cylinder(cylinder, r, roots.x, roots.y) == MAXFLOAT)
		roots.x = MAXFLOAT;
	return (roots);
}

