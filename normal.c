/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:08:23 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/05 19:09:48 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vdot(r->dir, rec->normal) < 0;
	rec->normal = (rec->front_face) ? rec->normal : vmult(rec->normal, -1);
}
