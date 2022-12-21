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
#include "../includes/scene.h"
#include "../includes/trace.h"
#include "../includes/structures.h"
#include "../includes/utils.h"
#include "../includes/print.h"
#include "../includes/rotate.h"

void debugPrintVec3(t_vec3 *new_point, char *str) {
    printf("@%s : %f , %f , %f\n",str, new_point->x, new_point->y, new_point->z);
}

// z -> camera->normal;
// x -> horiz;
// y -> vup;
void    rotate_world(t_scene *scene, t_object *world)
{
    // debugPrintVec3(&scene->camera.orig, "camera orig"); 
    t_vec3  move_p = vec3(-(scene->camera.real_orig.x), -(scene->camera.real_orig.y), -(scene->camera.real_orig.z));
    // debugPrintVec3(&move_p, "move_p");
    t_vec3  camera_normal = vunit(scene->c_normal); // 카메라좌표계의 z축. -> (0, 0, -1); camera->normal (1, 1, 0 ) -> (0, 0, 1);
    // debugPrintVec3(&camera_normal, "camera normal");
    t_vec3  rdup = vec3(0, 1, 0);
    if (camera_normal.y != 0.0 && (camera_normal.x == 0 && camera_normal.z == 0))
        rdup = vec3(0, 0, 1);
    t_vec3  horiz = vunit(vcross(rdup, camera_normal)); //x
    t_vec3  vup = vunit(vcross(camera_normal, horiz)); // y

    // debugPrintVec3(&horiz, "horiz");
    // debugPrintVec3(&vup, "rup");
    // debugPrintVec3(&camera_normal, "cameranormal");
   // printf("normal : %f , %f , %f\n", rdup.x, rdup.y, rdup.z);
   // printf("normal : %f , %f , %f\n", horiz.x, horiz.y, horiz.z);
   // printf("normal : %f , %f , %f\n", vup.x, vup.y, vup.z);

    t_rotate_seta   setas;
    setas.cosp = horiz.x;
    setas.sinp = horiz.y;
    setas.sint = camera_normal.z;
    setas.cost = -vup.z;
    //printf("@pt : %f, %f , %f , %f\n", setas.cosp, setas.sinp, setas.cost, setas.sint);

    t_rotate    r;
    // t_rotate    axis;
    // r.x = vec3(setas.cosp, setas.sinp, 0);
    // r.y = vec3(-(setas.sinp * setas.sint), setas.cosp * setas.sint, -setas.cost);
    // r.z = vec3(-(setas.sinp * setas.cost), setas.cosp * setas.cost, setas.sint);
    r.x = horiz;
    r.y = vup;
    r.z = camera_normal;
    // axis.x = horiz;
    // axis.y = vup;
    // axis.z = camera_normal;
    // debugPrintVec3(&(r.x), "axisx");
    // debugPrintVec3(&(r.y), "axisy");
    // debugPrintVec3(&(r.z), "axisz");

    t_light    *lights = scene->light->element;
    t_point3    newlights;
    // debugPrintVec3(lights, "lights before");
    lights->origin = vplus(lights->real_origin, move_p);
    newlights.x = vdot(r.x, lights->origin);
    newlights.y = vdot(r.y, lights->origin);
    newlights.z = vdot(r.z, lights->origin);
    lights->origin = newlights;
    // debugPrintVec3(&lights->origin, "lights");

    while(world)
    {
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
    cy->center = new_point;// 카메라 좌표.
    // debugPrintVec3(&cy->normal, "cy->normal");
    // debugPrintVec3(&cy->center, "cy->center");
}

void    rotate_pl(t_object *obj, t_vec3 move_p, t_rotate axis, t_rotate r)
{
    t_plain *pl;
    t_vec3  new_normal;
    t_vec3  new_point;

    (void)r;
    pl = obj->element;
    new_normal.x = vdot(axis.x, pl->normal);
    new_normal.y = vdot(axis.y, pl->normal);
    new_normal.z = vdot(axis.z, pl->normal);
    pl->normal = vunit(new_normal);

    pl->center = vplus(pl->real_center, move_p);
    new_point.x = vdot(axis.x, pl->center);
    new_point.y = vdot(axis.y, pl->center);
    new_point.z = vdot(axis.z, pl->center);
    pl->center = new_point;
 debugPrintVec3(&pl->center, "pl->center");
 debugPrintVec3(&pl->normal, "pl->normal");
}