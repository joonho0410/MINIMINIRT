/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:18:10 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/22 12:42:37 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scene.h"

t_camera	camera(t_canvas *canvas, t_parse *parse)
{
	t_camera	cam;
	double		focal_len;
	double		viewport_height;
	double		h;

	h = tan(M_PI * (parse->c.fov / 2) / 180.0);
	viewport_height = 2.0 * h;
	focal_len = 1;
	cam.orig = vec3(0, 0, 0);
	cam.real_orig = parse->c.view_point;
	cam.viewport_h = viewport_height;
	cam.viewport_w = viewport_height * canvas->aspect_ratio;
	cam.focal_len = focal_len;
	cam.horizontal = vec3(cam.viewport_w, 0, 0);
	cam.vertical = vec3(0, cam.viewport_h, 0);
	cam.left_bottom = vminus(vminus(vminus(vec3(0, 0, 0), \
	vdivide(cam.horizontal, 2)), vdivide(cam.vertical, 2)), \
			vec3(0, 0, focal_len));
	return (cam);
}
