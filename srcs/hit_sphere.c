/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:15:04 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/21 22:51:20 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structures.h"
#include "../includes/utils.h"
#include "../includes/trace.h"
#include <stdio.h>

t_bool	hit_sphere(t_object *sp, t_ray *ray, t_hit_record *rec)
{
	t_cal_sp	cal;

	rec->albedo = sp->albedo;
	cal.oc = vminus(ray->orig, ((t_sphere *)(sp->element))->center);
	cal.a = vlength2(ray->dir);
	cal.half_b = vdot(cal.oc, ray->dir);
	cal.c = vlength2(cal.oc) - ((t_sphere *)(sp->element))->radius2;
	cal.dis = cal.half_b * cal.half_b - cal.a * cal.c;
	if (cal.dis < 0)
		return (FALSE);
	cal.sqrtd = sqrt(cal.dis);
	cal.root = (((-cal.half_b) - cal.sqrtd) / cal.a);
	if (cal.root < rec->tmin || rec->tmax < cal.root)
	{
		cal.root = (((-cal.half_b) + cal.sqrtd) / cal.a);
		if (cal.root < rec -> tmin || rec -> tmax < cal.root)
			return (FALSE);
	}
	rec->t = cal.root;
	rec->p = ray_at(ray, cal.root);
	rec->p = vplus(rec->p, vmult(rec->normal, EPSILON));
	rec->normal = vdivide(vminus(rec->p, ((t_sphere *)(sp->element))->center), \
			((t_sphere *)(sp->element))->radius);
	set_face_normal(ray, rec);
	return (TRUE);
}
