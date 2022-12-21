/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:30:31 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/21 09:05:28 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	parse_ambient(char *src, t_parse *parse)
{
	if (parse->A.updated == FALSE)
	{
		parse->A.rate = get_rate(src);
		parse->A.color = get_color(skip_whitespace(src));
		parse->A.updated = TRUE;
	}
	else
		exit_print();
}

void	parse_camera(char *src, t_parse *parse)
{
	char	*tmp;

	if (parse->C.updated == FALSE)
	{
		parse->C.view_point = get_point(src);
		tmp = skip_whitespace(src);
		parse->C.normal = get_vector(tmp);
		tmp = skip_whitespace(tmp);
		parse->C.FOV = get_fov(tmp);
		parse->C.updated = TRUE;
	}
	else
		exit_print();
}

void	parse_light(char *src, t_parse *parse)
{
	if (parse->L.updated == FALSE)
	{
		parse->L.light_point = get_point(src);
		parse->L.bright_rate = get_rate(skip_whitespace(src));
		parse->L.updated = TRUE;
	}
	else
		exit_print();
}
