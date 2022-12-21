/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:31:21 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/21 09:04:18 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/scene.h"

void	parse_sphere(char *src, t_parse *parse)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = skip_whitespace(src);
	tmp2 = skip_whitespace(tmp1);
	oadd(&parse->ob_p, object(SP, sphere(get_point(src), get_double(tmp1) / 2), \
		zero_to_one(get_color(tmp2))));
}

void	parse_plane(char *src, t_parse *parse)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = skip_whitespace(src);
	tmp2 = skip_whitespace(tmp1);
	oadd(&parse->ob_p, object(PL, plain(get_point(src), get_vector(tmp1)), \
		zero_to_one(get_color(tmp2))));
}

void	parse_cylinder(char *src, t_parse *parse)
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;
	char	*tmp4;

	tmp1 = skip_whitespace(src);
	tmp2 = skip_whitespace(tmp1);
	tmp3 = skip_whitespace(tmp2);
	tmp4 = skip_whitespace(tmp3);
	oadd(&parse->ob_p, object(CY, cylinder(get_point(src), get_vector(tmp1), \
		get_double(tmp2) / 2, get_double(tmp3)), zero_to_one(get_color(tmp4))));
}
