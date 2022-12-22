/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:24:39 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/22 15:11:59 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/scene.h"
#include "../../includes/rotate.h"

t_scene	*scene_init(t_parse *parse)
{
	t_object	*lights;
	t_scene		*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (0);
	scene->canvas = canvas(400, 300);
	scene->camera = camera(&scene->canvas, parse);
	scene->world = parse->ob_p->next;
	scene->c_normal = parse->c.normal;
	lights = object(LIGHT_POINT, light_point(parse->l.light_point, \
					color3(1, 1, 1), parse->l.bright_rate), \
					zero_to_one(color3(0, 0, 0)));
	scene->light = lights;
	divide_3(&parse->a);
	scene->ambient = vmult(parse->a.color, parse->a.rate);
	rotate_world(scene, parse->ob_p->next);
	return (scene);
}
