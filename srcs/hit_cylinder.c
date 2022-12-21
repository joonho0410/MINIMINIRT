/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:01:58 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/21 23:17:29 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structures.h"
#include "../includes/utils.h"
#include "../includes/trace.h"
#include <stdio.h>

t_vec3	get_cylinder_normal(t_cylinder *cy, t_vec3 at)
{
	t_vec3	temp;
	t_vec3	center;
	double	t;

	temp = vminus(at, cy->center);
	t = vdot(vunit(cy->normal), temp);
	center = vplus(cy->center, vmult(vunit(cy->normal), t));
	return (vunit(vminus(at, center)));
}

t_bool	cylinder_hit_height(t_cylinder *cy, t_vec3 at)
{
	double	hit_height;
	double	max_height;

	hit_height = vdot(vminus(at, cy->center), vunit(cy->normal));
	max_height = cy->height / 2;
	if (fabs(hit_height) > max_height)
		return (FALSE);
	return (TRUE);
}

t_bool	hit_cylinder_cap(t_object *cy, t_ray *ray, \
		t_hit_record *rec, double height)
{
	t_cylinder		*cy2;
	t_cal_cy_cap	cal;
	t_vec3			circle_center;

	cy2 = cy -> element;
	circle_center = vplus(cy2 -> center, vmult(vunit(cy2 -> normal), height));
	cal.nom = vdot(vminus(circle_center, ray -> orig), vunit(cy2 -> normal));
	cal.denom = vdot(ray -> dir, vunit(cy2 -> normal));
	cal.root = cal.nom / cal.denom;
	cal.diam = vlength(vminus(circle_center, ray_at(ray, cal.root)));
	if (fabs(cy2 -> radius) < fabs(cal.diam))
		return (FALSE);
	if (cal.root < rec -> tmin || rec -> tmax < cal.root)
		return (FALSE);
	rec -> t = cal.root;
	rec -> p = ray_at(ray, cal.root);
	rec -> tmax = rec->t;
	rec -> normal = vunit(cy2 -> normal);
	set_face_normal(ray, rec);
	rec -> albedo = cy -> albedo;
	rec -> p = vplus(rec -> p, vmult(rec -> normal, EPSILON));
	return (TRUE);
}

void	hit_cylinder_rec(t_hit_record *rec, t_cal_cy cal, \
		t_object *cy, t_ray *ray)
{
	t_cylinder	*cy2;

	cy2 = cy->element;
	rec -> t = cal.root;
	rec -> p = ray_at(ray, cal.root);
	rec -> tmax = cal.root;
	rec -> normal = get_cylinder_normal(cy2, rec -> p);
	set_face_normal(ray, rec);
	rec -> albedo = cy -> albedo;
	rec -> p = vplus(rec -> p, vmult(rec -> normal, EPSILON));
}

t_bool	hit_cylinder(t_object *cy, t_ray *ray, t_hit_record *rec)
{
	t_cal_cy	cal;
	t_cylinder	*cy2;
	t_vec3		p;

	cy2 = cy->element;
	p = vminus(ray->orig, cy2->center);
	cal.a = vlength2(vcross(ray->dir, vunit(cy2->normal)));
	cal.half_b = vdot(vcross(ray->dir, vunit(cy2->normal)), \
			vcross(p, vunit(cy2->normal)));
	cal.c = vlength2(vcross(p, vunit(cy2->normal))) - pow(cy2->radius, 2);
	cal.dis = cal.half_b * cal.half_b - cal.a * cal.c;
	if (cal.dis < 0.0)
		return (FALSE);
	cal.sqrtd = sqrt(cal.dis);
	cal.root = (-cal.half_b - cal.sqrtd) / cal.a;
	if (cal.root < rec->tmin || rec->tmax < cal.root)
	{
		cal.root = (-cal.half_b + cal.sqrtd) / cal.a;
		if (cal.root < rec->tmin || rec->tmax < cal.root)
			return (FALSE);
	}
	if (!(cylinder_hit_height(cy2, ray_at(ray, cal.root))))
		return (FALSE);
	hit_cylinder_rec(rec, cal, cy, ray);
	return (TRUE);
}
