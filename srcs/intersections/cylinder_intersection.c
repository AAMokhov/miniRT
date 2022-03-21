#include "minirt.h"
//
//int		cy_boundary(t_vector ray, t_figures cy, t_cyvar var)
//{
//	var.p = ft_ray_at(ray, var.t);
//	if ((cy.normal_vec.x != 0) &&
//		(cy.normal_vec.y == 0 || cy.normal_vec.z == 0))
//	{
//		if (var.p.x < cy.pos.x - cy.height || var.p.x > cy.pos.x + cy.height)
//			return (0);
//	}
//	else if ((cy.normal_vec.y != 0) &&
//			 (cy.normal_vec.y == 0 || cy.normal_vec.z == 0))
//	{
//		if (var.p.y < cy.pos.y - cy.height || var.p.y > cy.pos.y + cy.height)
//			return (0);
//	}
//	else if ((cy.normal_vec.z != 0) &&
//			 (cy.normal_vec.y == 0 || cy.normal_vec.z == 0))
//	{
//		if (var.p.z < cy.pos.z - cy.height || var.p.z > cy.pos.z + cy.height)
//			return (0);
//	}
//	return (1);
//}
//
//int	ft_cl_intersect(t_camera *cam, t_vector *ray, t_figures	*cy)
//{
//	t_cyvar var;
//
//	var.r2 = cy->radius * 2 * cy->fig.cy.radius * 2;
//	var.top = ft_vec_add(cy->fig.cy.centre, ft_vec_mult(cy.normal,
//														cy->fig.cy.height));
//	var.bot = ft_vec_substraction(cy->fig.cy.centre, ft_vec_mult(cy.normal,
//													cy->fig.cy.height));
//	var.hc = ft_vec_substraction(var.top, var.bot);
//	var.h = ft_vec_normalize(var.hc);
//	var.w = ft_vec_substraction(cam->origin, var.bot);
//	var.v = ray;
////	if (!(var.t = cy_calc(var, hit, i)))
////		return (0);
//	if (!cy_boundary(ray, cy, var))
//		return (0);
////	hit->dist = var.t;
////	hit->pos = ft_ray_at(ray, var.t);
////	hit->normal_vec = get_cy_normal(hit->pos, cy);
////	hit->pos = ft_vec_add(hit->pos, ft_vec_multi_double(hit->normal_vec,
////														EPSILON));
//	return (1);
//}