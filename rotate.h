/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:20:26 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/19 09:12:30 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "scene.h"
#include "trace.h"
#include "structures.h"
#include "utils.h"
#include "print.h"


void    rotate_world(t_scene *scene, t_object *world, t_parse *parse);
void    rotate_sp(t_object *obj, t_vec3 move_p, t_rotate axis, t_rotate_seta point);
void    rotate_pl(t_object *obj, t_vec3 move_p, t_rotate axis, t_rotate_seta point);
void    rotate_cy(t_object *obj, t_vec3 move_p, t_rotate axis, t_rotate_seta point);