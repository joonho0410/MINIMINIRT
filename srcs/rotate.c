/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:20:26 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/21 08:08:09 by seungsle         ###   ########.fr       */
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

void    rotate_world(t_scene *scene, t_object *world)
{
    t_vec3  move_p = vec3(-(scene->camera.real_orig.x), -(scene->camera.real_orig.y), -(scene->camera.real_orig.z));
    t_vec3  camera_normal = vunit(scene->c_normal);
    t_vec3  rdup = vec3(0, 1, 0);
    if (camera_normal.y != 0.0 && (fabs(camera_normal.x) < EPSILON && fabs(camera_normal.z) < EPSILON))
        rdup = vec3(0, 0, 1);
    t_vec3  horiz = vunit(vcross(rdup, camera_normal));
    t_vec3  vup = vunit(vcross(camera_normal, horiz));

    t_rotate    r;
    r.x = horiz;
    r.y = vup;
    r.z = camera_normal;

    t_light    *lights = scene->light->element;
    t_point3    newlights;
    lights->origin = vplus(lights->real_origin, move_p);
    newlights.x = vdot(r.x, lights->origin);
    newlights.y = vdot(r.y, lights->origin);
    newlights.z = vdot(r.z, lights->origin);
    lights->origin = newlights;

    while(world)
    {
        printf("%d\n", world->type);
        if (world->type == SP)
            rotate_sp(world, move_p, r, r);
        if (world->type == PL)
            rotate_pl(world, move_p, r, r);
        if (world->type == CY)
            rotate_cy(world, move_p, r, r);
        world = world->next;
    }
}

void    rotate_sp(t_object *obj, t_vec3 move_p, t_rotate axis, t_rotate r)
{
    t_sphere    *sp;
    t_vec3      new_point;

    (void)r;
    sp = obj->element;
    sp->center = vplus(sp->real_center, move_p);
    new_point.x = vdot(axis.x, sp->center);
    new_point.y = vdot(axis.y, sp->center);
    new_point.z = vdot(axis.z, sp->center);
    sp->center = new_point;
}

void    rotate_cy(t_object *obj, t_vec3 move_p, t_rotate axis, t_rotate r)
{
    t_cylinder *cy;
    t_vec3      new_normal;
    t_vec3      new_point;

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

void    rotate_pl(t_object *obj, t_vec3 move_p, t_rotate axis, t_rotate r)
{
    t_plain *pl;
    t_vec3  new_normal;
    t_vec3  new_point;

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
