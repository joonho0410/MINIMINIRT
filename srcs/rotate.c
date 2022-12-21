/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:20:26 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/21 22:16:33 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "../includes/scene.h"
#include "../includes/trace.h"
#include "../includes/structures.h"
#include "../includes/utils.h"
#include "../includes/print.h"
#include "../includes/rotate.h"

void	rotate_world_obj(t_object *world, t_rotate_var var, t_rotate r)
{
	while (world)
	{
		if (world->type == SP)
			rotate_sp(world, var.move_p, r, r);
		if (world->type == PL)
			rotate_pl(world, var.move_p, r, r);
		if (world->type == CY)
			rotate_cy(world, var.move_p, r, r);
		world = world->next;
	}
}

void	rotate_world(t_scene *scene, t_object *world)
{
	t_rotate_var	var;
	t_rotate		r;

	var.move_p = vec3(-(scene->camera.real_orig.x), \
	-(scene->camera.real_orig.y), -(scene->camera.real_orig.z));
	var.camera_normal = vunit(scene->c_normal);
	var.rdup = vec3(0, 1, 0);
	if (var.camera_normal.y != 0.0 && (fabs(var.camera_normal.x) < EPSILON && \
	fabs(var.camera_normal.z) < EPSILON))
		var.rdup = vec3(0, 0, 1);
	var.horiz = vunit(vcross(var.rdup, var.camera_normal));
	var.vup = vunit(vcross(var.camera_normal, var.horiz));
	r.x = var.horiz;
	r.y = var.vup;
	r.z = var.camera_normal;
	var.lights = scene->light->element;
	var.lights->origin = vplus(var.lights->real_origin, var.move_p);
	var.newlights.x = vdot(r.x, var.lights->origin);
	var.newlights.y = vdot(r.y, var.lights->origin);
	var.newlights.z = vdot(r.z, var.lights->origin);
	var.lights->origin = var.newlights;
	rotate_world_obj(world, var, r);
}

void	rotate_sp(t_object *obj, t_vec3 move_p, t_rotate axis, t_rotate r)
{
	t_sphere	*sp;
	t_vec3		new_point;

	(void)r;
	sp = obj->element;
	sp->center = vplus(sp->real_center, move_p);
	new_point.x = vdot(axis.x, sp->center);
	new_point.y = vdot(axis.y, sp->center);
	new_point.z = vdot(axis.z, sp->center);
	sp->center = new_point;
}

void	rotate_cy(t_object *obj, t_vec3 move_p, t_rotate axis, t_rotate r)
{
	t_cylinder	*cy;
	t_vec3		new_normal;
	t_vec3		new_point;

	(void)r;
	cy = obj->element;
	new_normal.x = vdot(axis.x, cy->real_normal);
	new_normal.y = vdot(axis.y, cy->real_normal);
	new_normal.z = vdot(axis.z, cy->real_normal);
	cy->normal = vunit(new_normal);
	cy->center = vplus(cy->real_center, move_p);
	new_point.x = vdot(axis.x, cy->center);
	new_point.y = vdot(axis.y, cy->center);
	new_point.z = vdot(axis.z, cy->center);
	cy->center = new_point;
}

void	rotate_pl(t_object *obj, t_vec3 move_p, t_rotate axis, t_rotate r)
{
	t_plain	*pl;
	t_vec3	new_normal;
	t_vec3	new_point;

	(void)r;
	pl = obj->element;
	new_normal.x = vdot(axis.x, pl->real_normal);
	new_normal.y = vdot(axis.y, pl->real_normal);
	new_normal.z = vdot(axis.z, pl->real_normal);
	pl->normal = vunit(new_normal);
	pl->center = vplus(pl->real_center, move_p);
	new_point.x = vdot(axis.x, pl->center);
	new_point.y = vdot(axis.y, pl->center);
	new_point.z = vdot(axis.z, pl->center);
	pl->center = new_point;
}
