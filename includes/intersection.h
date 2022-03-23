/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtentaco <dtentaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:01:18 by dtentaco          #+#    #+#             */
/*   Updated: 2022/03/24 01:15:35 by dtentaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERSECTION_H
# define INTERSECTION_H

t_pair	run_intersect(void *ray, t_figures *fig);
t_pair	ft_sph_intersect(void *is_ray, void *is_sphere);
t_pair	ft_pl_intersect(void *is_ray, void	*is_plane);

#endif
