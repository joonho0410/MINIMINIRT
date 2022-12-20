/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:20:26 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/20 12:00:40 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "scene.h"
#include "trace.h"
#include "structures.h"
#include "utils.h"
#include "print.h"
#include "rotate.h"

void debugPrintVec3(t_vec3 *new_point, char *str) {
    printf("@%s : %f , %f , %f\n",str, new_point->x, new_point->y, new_point->z);
}

// z -> camera->normal;
// x -> horiz;
// y -> vup;
void    rotate_world(t_scene *scene, t_object *world, t_parse *parse)
{
    (void)parse;
    t_vec3  move_p = vec3(-(scene->camera.orig.x), -(scene->camera.orig.y), -(scene->camera.orig.z));
    // debugPrintVec3(&move_p, "move_p");
    t_vec3  camera_normal =  scene->c_normal; // vunit(vec3(0, 0, 1)); // parse->C.normal; // 카메라좌표계의 z축. -> (0, 0, -1); camera->normal (1, 1, 0 ) -> (0, 0, 1);
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
    setas.sint = vup.z;
    setas.cost = -(camera_normal.z);
    // printf("@pt : %f, %f , %f , %f\n", setas.cosp, setas.sinp, setas.cost, setas.sint);

    t_rotate    axis;
    // axis.x = vec3(setas.cosp, setas.sinp, 0);
    // axis.y = vec3(-(setas.sinp * setas.sint), setas.cosp * setas.sint, -setas.cost);
    // axis.z = vec3(-(setas.sinp * setas.cost), setas.cosp * setas.cost, setas.sint);
    axis.x = horiz;
    axis.y = vup;
    axis.z = camera_normal;
    // debugPrintVec3(&(axis.x), "axisx");
    // debugPrintVec3(&(axis.y), "axisy");
    // debugPrintVec3(&(axis.z), "axisz");

    t_light    *lights = scene->light->element;
    lights->origin = vplus(lights->origin, move_p);


    while(world)
    {
        if (world->type == SP)
            rotate_sp(world, move_p, axis, setas);
        if (world->type == PL)
            rotate_pl(world, move_p, axis, setas);
        if (world->type == CY)
            rotate_cy(world, move_p, axis, setas);
        world = world->next;
    }
}

void    rotate_sp(t_object *obj, t_vec3 move_p, t_rotate axis, t_rotate_seta seta)
{
    t_sphere *sp;

    (void)axis;
    (void)seta;
    sp = obj->element;
    sp->center = vplus(sp->center, move_p);
}

void    rotate_cy(t_object *obj, t_vec3 move_p, t_rotate axis, t_rotate_seta seta)
{
    t_cylinder *cy;
    t_vec3      new_normal;
    t_vec3      new_point;

    (void)seta;
    cy = obj->element;
    // debugPrintVec3(&cy->center);
    new_normal = vmult(axis.x, vunit(cy->normal).x);
    new_normal = vplus(new_normal, vmult(axis.y, vunit(cy->normal).y));
    new_normal = vplus(new_normal, vmult(axis.z, vunit(cy->normal).z));
    cy->normal = vunit(new_normal);

    cy->center = vplus(cy->center, move_p);
    // debugPrintVec3(&cy->center, "center");
    // debugPrintVec3(&new_normal, "normal");
    // new_point = vmult_(axis.x, (cy->center)); // x 좌표값
    // new_point = vplus(new_point, vmult_(axis.y, (cy->center)));
    // new_point = vplus(new_point, vmult_(axis.z, (cy->center)));
    new_point.x = vdot(axis.x, cy->center);
    new_point.y = vdot(axis.y, cy->center);
    new_point.z = vdot(axis.z, cy->center);
    cy->center = new_point;
    //debugPrintVec3(&cy->center, "center");
}

void    rotate_pl(t_object *obj, t_vec3 move_p, t_rotate axis, t_rotate_seta seta)
{
    t_plain *pl;
    t_vec3  new_normal;
    t_vec3  new_point;

    (void)seta;
    pl = obj->element;
    pl->center = vplus(pl->center, move_p);
    //printf("normal : %f , %f , %f\n", pl->normal.x, pl->normal.y, pl->normal.z);
    new_normal = vmult(axis.x, vunit(pl->normal).x);
    new_normal = vplus(new_normal, vmult(axis.y, vunit(pl->normal).y));
    new_normal = vplus(new_normal, vmult(axis.z, vunit(pl->normal).z));
    pl->normal = vunit(new_normal);

    new_point.x = vdot(axis.x, pl->center);
    new_point.y = vdot(axis.y, pl->center);
    new_point.z = vdot(axis.z, pl->center);
    pl->center = new_point;
    //printf("normal : %f , %f , %f\n", pl->normal.x, pl->normal.y, pl->normal.z);
}
