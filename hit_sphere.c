/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:15:04 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/07 20:47:33 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

#include <stdio.h>

t_bool	hit_sphere(t_object *sp, t_ray *ray, t_hit_record *rec)
{
	t_sphere *sp2;
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	dis;
	double	sqrtd;
	double	root;
	
	sp2 = sp->element;
	rec->albedo = sp->albedo;
	oc = vminus(ray->orig, ((t_sphere *)(sp->element))->center);
	a = vlength2(ray->dir);
	half_b = vdot(oc, ray->dir);
	c = vlength2(oc) - ((t_sphere *)(sp->element))->radius2;
	dis = half_b * half_b - a * c;
	if (dis < 0)
		return (FALSE);
	sqrtd = sqrt(dis);
	root = (-half_b -sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vdivide(vminus(rec->p, ((t_sphere *)(sp->element))->center), ((t_sphere *)(sp->element))->radius);
	rec->p = vplus(rec->p, vmult(rec->normal, EPSILON));
	set_face_normal(ray, rec);
	return (TRUE);
}

t_bool	hit_plain(t_object *pl, t_ray *ray, t_hit_record *rec)
{
	t_plain	*pl2;
	double	denom;
	double	nom;
	double	root;

	pl2 = pl->element;
	denom = vdot(ray->dir, vunit(pl2->normal));
	if (fabs(denom) < EPSILON)
		return (FALSE);
	nom = vdot(vminus(pl2->center, ray->orig), vunit(pl2->normal));
	root = nom / denom;
	if (root < rec->tmin || rec->tmax < root)
		return(FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->tmax = root;
	rec->albedo = pl->albedo;
	if (denom > 0.000)
		rec->normal = vmult(vunit(pl2->normal), -1);
	else
		rec->normal = vunit(pl2->normal);
	return (TRUE);	
}

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
	//printf("height = %f\n", hit_height);
	max_height = cy->height / 2;
	if (fabs(hit_height) > max_height)
		return (FALSE);
	return (TRUE);
}

t_bool	hit_cylinder_cap(t_object *cy, t_ray *ray, t_hit_record *rec, double height)
{
	t_cylinder	*cy2;
	t_vec3		circle_center;
	double		root;
	double		nom;
	double		denom;
	double		diam;

	cy2= cy->element;
	circle_center = vplus(cy2->center, vmult(vunit(cy2->normal), height));
	//circle_center = cy2->center;
	nom = vdot(vminus(circle_center, ray->orig), vunit(cy2->normal));
	denom = vdot(ray->dir, vunit(cy2->normal));
	root = nom / denom;
	diam = vlength(vminus(circle_center, ray_at(ray, root)));
	
	if(fabs(cy2->radius) < fabs(diam))
		return (FALSE);
	if(root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->tmax = rec->t;
	rec->normal = vunit(cy2->normal);
	set_face_normal(ray, rec);
	rec->albedo = cy->albedo;// temp;
	return (TRUE);
}

t_bool	hit_cylinder(t_object *cy, t_ray *ray, t_hit_record *rec)
{
	t_cylinder *cy2;

	cy2 = cy->element;
	t_vec3	p;
	double	a;
	double	half_b;
	double	c;
	double	dis;
	double	root;
	double	sqrtd;
	
	p = vminus(ray->orig, cy2->center);
	a = vlength2(vcross(ray->dir, vunit(cy2->normal)));
	half_b = vdot(vcross(ray->dir, vunit(cy2->normal)), vcross(p, vunit(cy2->normal)));
	c = vlength2(vcross(p, vunit(cy2->normal))) - pow(cy2->radius, 2);
	
	dis = half_b * half_b - a * c;
	if (dis < 0.0)
		return (FALSE);
	sqrtd = sqrt(dis);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	if (!(cylinder_hit_height(cy2, ray_at(ray,root))))
	  	return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->tmax = root;
	rec->normal = get_cylinder_normal(cy2, rec->p);
	set_face_normal(ray, rec);
	rec->albedo = cy->albedo;
	return (TRUE);
}
