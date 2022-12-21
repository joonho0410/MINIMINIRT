/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:12:01 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/21 22:02:08 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structures.h"
#include "../includes/scene.h"

t_object	*object(t_object_type type, void *element, t_color3 albedo)
{
	t_object	*new;

	new = (t_object *)malloc(sizeof(t_object));
	if (!new)
		return (0);
	new->type = type;
	new->element = element;
	new->next = 0;
	new->albedo = albedo;
	return (new);
}

t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere	*sp;

	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sp)
		return (0);
	sp->real_center = center;
	sp->center = center;
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}

t_plain	*plain(t_point3 center, t_vec3 normal)
{
	t_plain	*pl;

	pl = (t_plain *)malloc(sizeof(t_plain));
	if (!pl)
		return (0);
	pl->real_center = center;
	pl->center = center;
	pl->real_normal = normal;
	pl->normal = normal;
	return (pl);
}

t_cylinder	*cylinder(t_point3 center, t_vec3 normal, \
		double radius, double height)
{
	t_cylinder	*cy;

	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cy)
		return (0);
	cy->real_center = center;
	cy->center = center;
	cy->real_normal = normal;
	cy->normal = normal;
	cy->radius = radius / 2;
	cy->height = height;
	return (cy);
}

t_light	*light_point(t_point3 light_origin, \
		t_color3 light_color, double bright_ratio)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		return (0);
	light->real_origin = light_origin;
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}
