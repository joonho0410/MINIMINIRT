/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:30:31 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/22 12:42:51 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	parse_ambient(char *src, t_parse *parse)
{
	if (parse->a.updated == FALSE)
	{
		parse->a.rate = get_rate(src);
		parse->a.color = get_color(skip_whitespace(src));
		parse->a.updated = TRUE;
	}
	else
		exit_print();
}

void	parse_camera(char *src, t_parse *parse)
{
	char	*tmp;

	if (parse->c.updated == FALSE)
	{
		parse->c.view_point = get_point(src);
		tmp = skip_whitespace(src);
		parse->c.normal = get_vector(tmp);
		tmp = skip_whitespace(tmp);
		parse->c.fov = get_fov(tmp);
		parse->c.updated = TRUE;
	}
	else
		exit_print();
}

void	parse_light(char *src, t_parse *parse)
{
	if (parse->l.updated == FALSE)
	{
		parse->l.light_point = get_point(src);
		parse->l.bright_rate = get_rate(skip_whitespace(src));
		parse->l.updated = TRUE;
	}
	else
		exit_print();
}
