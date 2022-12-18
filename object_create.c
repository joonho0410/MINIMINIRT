/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:12:01 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/18 22:15:40 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "scene.h"

t_object	*object(t_object_type type, void *element, t_color3 albedo)
{
	t_object	*new;

	if (!(new = (t_object *)malloc(sizeof(t_object))))
		return (0);
	new->type = type;
	new->element = element;
	new->next = 0;
	new->albedo = albedo;
	return (new);
}

t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere *sp;

	if (!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (0);
	sp->center = center;
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}

t_plain	*plain(t_point3 center, t_vec3 normal)
{
	t_plain	*pl;

	if (!(pl = (t_plain *)malloc(sizeof(t_plain))))
		return (0);
	pl->center = center;
	pl->normal = normal;
	return (pl);
}

t_cylinder	*cylinder(t_point3 center, t_vec3 normal, double radius, double height)
{
	t_cylinder *cy;

	if (!(cy = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return (0);
	cy->center = center;
	cy->normal = normal;
	cy->radius = radius / 2;
	cy->height = height;
	return (cy);
}

t_light	*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio)
{
	t_light	*light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		return (0);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}
