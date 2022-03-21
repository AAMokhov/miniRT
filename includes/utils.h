/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:02:41 by kclassie          #+#    #+#             */
/*   Updated: 2022/03/14 14:02:46 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	ft_error_exit(int code);
void	*enh_malloc(unsigned int size);
void	scene_error(char *message);
void	fatal(char *message);
#endif
