/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:08:12 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/21 22:10:03 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trace.h"

//ray 생성자(정규화 된 ray)
t_ray	ray(t_point3 orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}

//ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점.
t_point3	ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = vplus(ray->orig, vmult(ray->dir, t));
	return (at);
}

/* * * * 추가 * * * */
//primary_ray 생성자
t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.orig = vec3(0, 0, 0);
	ray.dir = vunit(vminus(vplus(vplus(cam->left_bottom, \
			vmult(cam->horizontal, u)), vmult(cam->vertical, v)), ray.orig));
	return (ray);
}

//광선이 최종적으로 얻게된 픽셀의 색상 값을 리턴.
t_color3	ray_color(t_scene *scene)
{
	double	t;

	scene->rec = record_init();
	if (hit(scene->world, &scene->ray, &scene->rec))
		return (phong_lighting(scene));
	t = 0.5 * (scene->ray.dir.y + 1.0);
	return (vplus(vmult(color3(1, 1, 1), 1.0 - t), \
				vmult(color3(0.5, 0.7, 1.0), t)));
}

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}
