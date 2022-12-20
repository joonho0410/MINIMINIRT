/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:18:10 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/19 09:19:56 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_camera    camera(t_canvas *canvas, t_parse *parse)
{
    // camera FOV, view point 설정
    t_camera    cam;
    double      focal_len;
    double      viewport_height;
    double      h;

    //fov
    double  seta = parse->C.FOV; // 0 < seta < 180;
    h = tan(M_PI * (seta / 2) / 180.0);

    /*
    //카메라 회전
    t_vec3      nv = vec3(0, 0.1 , -1); // 카메라의 기본 벡터방향
    t_vec3      rdup = vec3(0, 1 ,0);
    if (nv.y != 0.0 && (nv.x == 0.0 && nv.z == 0.0))
        rdup = vec3(0, 0, 1);
    rdup = vunit(rdup);
    t_vec3      horiz = vunit(vcross(rdup, nv));
    t_vec3      vup = vunit(vcross(nv, horiz));
    */
    //카메라 뷰포트 그리기
    viewport_height = 2.0 * h;
    focal_len = 1;

    cam.orig = parse->C.view_point;
    cam.viewport_h = viewport_height;  
    cam.viewport_w = viewport_height * canvas->aspect_ratio;
    cam.focal_len = focal_len;
    cam.horizontal = vec3(cam.viewport_w, 0, 0);
    cam.vertical = vec3(0, cam.viewport_h, 0);
    // 왼쪽 아래 코너점 좌표, origin - horizontal / 2 - vertical / 2 - vec3(0,0,focal_length)
    cam.left_bottom = vminus(vminus(vminus(cam.orig, vdivide(cam.horizontal, 2)),
                                vdivide(cam.vertical, 2)), vec3(0, 0, focal_len));
    //cam.left_bottom = vplus(cam.left_bottom, vec3(0.5,0.5,0));
    /*t_point3    view_center = vplus(orig, vunit(nv));
    cam.left_bottom = vplus(view_center, vmult(horiz, cam.viewport_w / 2));
    cam.left_bottom = vminus(cam.left_bottom, vmult(vup, cam.viewport_h / 2));
    */ 
    return (cam);
}
