/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:20:25 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/21 22:05:56 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trace.h"

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (vminus(v, vmult(n, vdot(v, n) * 2)));
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_light_var	var;

	var.light_dir = vminus(light->origin, scene->rec.p);
	var.light_len = vlength(var.light_dir);
	var.light_ray = ray(vplus(scene->rec.p, vmult(scene->rec.normal, \
					EPSILON)), var.light_dir);
	if (in_shadow(scene->world, var.light_ray, var.light_len))
		return (color3(0, 0, 0));
	var.light_dir = vunit(var.light_dir);
	var.kd = fmax(vdot(scene->rec.normal, var.light_dir), 0.0);
	var.diffuse = vmult(light->light_color, var.kd);
	var.view_dir = vunit(vmult(scene->ray.dir, -1));
	var.reflect_dir = reflect(vmult(var.light_dir, -1), scene->rec.normal);
	var.ksn = 64;
	var.ks = 0.5;
	var.spec = pow(fmax(vdot(var.view_dir, var.reflect_dir), 0.0), var.ksn);
	var.specular = vmult(vmult(light->light_color, var.ks), var.spec);
	var.brightness = light->bright_ratio * LUMEN;
	return (vmult(vplus(vplus(scene->ambient, var.diffuse), \
	var.specular), var.brightness));
}

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
			light_color = vplus(light_color, point_light_get(scene, \
						lights->element));
		lights = lights -> next;
	}
	light_color = vplus(light_color, scene->ambient);
	return (vmin(vmult_(light_color, scene->rec.albedo), color3(1, 1, 1)));
}

t_bool	in_shadow(t_object *objs, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(objs, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}
