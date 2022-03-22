#ifndef SPHERE_H
# define SPHERE_H

typedef struct	s_sphere
{
	t_vector	*centre;
	float		radius;
	int			inside;
}				t_sphere;

t_sphere	*ft_new_sphere(t_vector *centre, float	radius);

#endif
