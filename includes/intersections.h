/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:02:27 by kclassie          #+#    #+#             */
/*   Updated: 2022/03/14 14:02:32 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

int	ft_sph_intersect(t_camera *cam, t_vector *ray, t_sphere *sphere);
int	ft_pl_intersect(t_camera *cam, t_vector *ray, t_plane *plane);

#endif
