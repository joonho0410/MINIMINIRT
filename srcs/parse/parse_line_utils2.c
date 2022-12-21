/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:28:50 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/21 09:05:30 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

double	get_rate(char *src)
{
	double	ret;

	valid_decimal(src);
	ret = ft_atod(src);
	if (ret < 0.0 || ret > 1.0)
		exit_print();
	return (ret);
}

t_color3	get_color(char *src)
{
	t_color3	color;
	t_set3		set3;

	slice_set(src, &set3);
	valid_digit_set(&set3);
	color.x = ft_atol(set3.src1);
	color.y = ft_atol(set3.src2);
	color.z = ft_atol(set3.src3);
	if (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255 || \
		color.z < 0 || color.z > 255)
		exit_print();
	return (color);
}

t_point3	get_point(char *src)
{
	t_point3	point;
	t_set3		set3;

	slice_set(src, &set3);
	valid_decimal_set(&set3);
	point.x = ft_atod(set3.src1);
	point.y = ft_atod(set3.src2);
	point.z = ft_atod(set3.src3);
	return (point);
}

t_vec3	get_vector(char *src)
{
	t_vec3	vec;
	t_set3	set3;

	slice_set(src, &set3);
	valid_decimal_set(&set3);
	vec.x = ft_atod(set3.src1);
	vec.y = ft_atod(set3.src2);
	vec.z = ft_atod(set3.src3);
	if (vec.x < -1.0 || vec.x > 1.0 || vec.y < -1.0 || vec.y > 1.0 || \
		vec.z < -1.0 || vec.z > 1.0)
		exit_print();
	return (vec);
}

double	get_fov(char *src)
{
	double	ret;

	valid_decimal(src);
	ret = ft_atod(src);
	if (ret < 0.0 || ret > 180.0)
		exit_print();
	return (ret);
}
