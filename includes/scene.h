/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:17:21 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/21 08:46:14 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "./structures.h"
# include "./utils.h"
# include "./parsing.h"

t_canvas    canvas(int  width, int height);
t_camera    camera(t_canvas *canvas, t_parse *parse);
t_sphere	*sphere(t_point3 center, double radius);
t_plain		*plain(t_point3 center, t_vec3 normal);
t_cylinder	*cylinder(t_point3 center, t_vec3 normal, double radius, double height);
t_object	*object(t_object_type type, void *element, t_color3 albedo);
t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio);


#endif
