#ifndef SPHERE_H
# define SPHERE_H

typedef struct	s_sphere
{
	t_vector	*centre;
	float 		radius;
	t_vector	*next;
}				t_sphere;

t_sphere	*ft_new_sphere(t_vector *center, float	radius);

#endif
