/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:02:08 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/21 23:02:09 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structures.h"
#include "../includes/utils.h"
#include "../includes/trace.h"
#include <stdio.h>

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
		return (FALSE);
	rec -> t = root;
	rec -> p = ray_at(ray, root);
	rec->tmax = root;
	rec->albedo = pl->albedo;
	if (denom > 0.000)
		rec->normal = vmult(vunit(pl2->normal), -1);
	else
		rec->normal = vunit(pl2->normal);
	rec->p = vplus(rec->p, vmult(rec->normal, EPSILON));
	return (TRUE);
}
