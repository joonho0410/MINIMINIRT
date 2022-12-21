/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:20:19 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/21 09:00:36 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int	is_dot(char c)
{
	if (c == '.')
		return (TRUE);
	return (FALSE);
}

int	is_empty(char *str)
{
	if (str && ft_strncmp(str, "", -1))
		return (TRUE);
	return (FALSE);
}

void	divide_3(t_ambient_p *a)
{
	a->color.x /= 255;
	a->color.y /= 255;
	a->color.z /= 255;
}

t_color3	zero_to_one(t_color3 color)
{
	color.x /= 255;
	color.y /= 255;
	color.z /= 255;
	return (color);
}
