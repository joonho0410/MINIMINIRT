/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:33:15 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/22 12:42:11 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing_utils.h"
#include "../../includes/utils.h"
#include "../../includes/rotate.h"

void	parse_line(char *src, t_parse *parse)
{
	if (valid_identifier(src, "A", 1))
		parse_ambient(skip_whitespace(src), parse);
	else if (valid_identifier(src, "C", 1))
		parse_camera(skip_whitespace(src), parse);
	else if (valid_identifier(src, "L", 1))
		parse_light(skip_whitespace(src), parse);
	else if (valid_identifier(src, "sp", 2))
		parse_sphere(skip_whitespace(src), parse);
	else if (valid_identifier(src, "pl", 2))
		parse_plane(skip_whitespace(src), parse);
	else if (valid_identifier(src, "cy", 2))
		parse_cylinder(skip_whitespace(src), parse);
	else
		exit_print();
}

t_scene	*parsing(int argc, char **argv, t_parse *parse)
{
	t_object	*ob_p;

	ob_p = ofirst();
	parse->ob_p = ob_p;
	parse->a.updated = FALSE;
	parse->c.updated = FALSE;
	parse->l.updated = FALSE;
	valid_argument(argc);
	valid_file(argv[1]);
	valid_contents(open_and_read(argv[1]), parse);
	return (scene_init(parse));
}
