
#ifndef SPHERE_INTERSECTION_H
# define SPHERE_INTERSECTION_H

t_pair	run_intersect(void *ray, t_figures *fig);
t_pair	ft_sph_intersect(void *is_ray, void *is_sphere);
t_pair	ft_pl_intersect(void *is_ray, void	*is_plane);
t_pair	ft_cy_intersect(void *is_ray, void	*is_cylinder); //TODO

#endif
