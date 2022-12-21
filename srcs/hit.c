/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:22:09 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/21 08:09:00 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trace.h"
#include <stdio.h>

t_bool	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_anything = FALSE;
	while (world)
	{
		if (hit_obj(world, ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}

t_bool	hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool		hit_result;
	t_cylinder	*cy;

	hit_result = FALSE;
	if (world->type == SP)
		hit_result = hit_sphere(world, ray, rec);
	if (world->type == PL)
		hit_result = hit_plain(world, ray, rec);
	if (world->type == CY)
	{
		cy = world->element;
		if (hit_cylinder_cap(world, ray, rec, cy->height / 2))
		   	hit_result = TRUE;
		if (hit_cylinder_cap(world, ray, rec, -(cy->height / 2)))
		   	hit_result = TRUE;
		if (hit_cylinder(world, ray, rec))
			hit_result = TRUE;
	}
	return (hit_result);
}

