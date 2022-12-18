/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:33:15 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/18 21:55:33 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "parsing_utils.h"
#include <stdio.h>
#include <fcntl.h>

void exit_print(void)
{
	printf("Error\n");
	exit(1);
}

void perror_exit(char *str)
{
	perror(str);
	exit(1);
}

char *find_char(char *str, char find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == find)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

void valid_argument(int argc)
{
	if (argc != 2)
		exit_print();
}

void valid_file(char *str)
{
	char *temp;

	temp = find_char(str, '.');
	if (temp == NULL)
		exit_print();
	temp = find_char(temp, '.');
	if (temp != NULL)
		exit_print();
}

char *open_and_read(char *file_name)
{
	int fd;
	off_t file_size;
	char *file_contents;
	ssize_t bytes_read;
	
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		perror_exit("Error: opening file");
	file_size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	file_contents = malloc(file_size * sizeof(char));
	if (file_contents == NULL)
		perror_exit("Error: malloc failed");
	bytes_read = read(fd, file_contents, file_size);
	if (bytes_read == -1)
		perror_exit("Error: reading from file");
	return (file_contents);
}

int valid_identifier(char *src, char *c, int n)
{
	if (ft_strncmp(src, c, n) == 0)
	{
		if (is_whitespace(src[n]))
			return (TRUE);
	}
	return (FALSE);
}

char *skip_whitespace(char *src)
{
	int	i;

	i = 0;
	while (src[i] && !is_whitespace(src[i]))
		i++;
	while (src[i] && is_whitespace(src[i]))
		i++;
	return (&src[i]);
}

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int is_dot(char c)
{
	if (c == '.')
		return (TRUE);
	return (FALSE);	
}

void valid_decimal(char *src)
{
	int	i;

	i = 0;
	if (src[i] == '-' || src[i] == '+')
		i++;
	if (is_whitespace(src[i]))
		exit_print();
	while (!is_whitespace(src[i]) && !is_dot(src[i]))
	{
		if (!is_digit(src[i]) && !is_dot(src[i]))
			exit_print();
		i++;
	}
	if (is_dot(src[i++]))
	{
		while (!is_whitespace(src[i]))
		{
			if (!is_digit(src[i]))
				exit_print();
			i++;
		}
	}
}

void valid_digit(char *src)
{
	int	i;

	i = 0;
	if (src[i] == '-' || src[i] == '+')
		i++;
	if (is_whitespace(src[i]))
		exit_print();
	while (!is_whitespace(src[i]))
	{
		if (!is_digit(src[i]))
			exit_print();
		i++;
	}
}

void valid_decimal_set(t_set3 *set3)
{
	valid_decimal(set3->src1);
	valid_decimal(set3->src2);
	valid_decimal(set3->src3);
}

void valid_digit_set(t_set3 *set3)
{
	valid_digit(set3->src1);
	valid_digit(set3->src2);
	valid_digit(set3->src3);
}

void slice_set(char *src, t_set3 *set3)
{
	char *tmp1;
	char *tmp2;
	char *tmp3;
	int	i;

	tmp1 = find_char(src, ',');
	tmp2 = find_char(tmp1 + 1, ',');
	i = 0;
	while (1)
	{
		if (!tmp2[i] || is_whitespace(tmp2[i]))
		{
			tmp3 = &tmp2[i];
			break ;
		}
		i++;
	}
	set3->src1 = (char *)malloc(sizeof(char) * (tmp1 - src + 1));
	set3->src2 = (char *)malloc(sizeof(char) * (tmp2 - tmp1 + 1));
	set3->src3 = (char *)malloc(sizeof(char) * (tmp3 - tmp2 + 1));
	ft_strlcpy(set3->src1, src, tmp1 - src);
	ft_strlcpy(set3->src2, tmp1 + 1, tmp2 - tmp1);
	ft_strlcpy(set3->src3, tmp2 + 1, tmp3 - tmp2);
}

double get_rate(char *src)
{
	double	ret;

	valid_decimal(src);
	ret = ft_atod(src);
	if (ret < 0.0 || ret > 1.0)
		exit_print();
	return (ret);
}

t_color3 get_color(char *src)
{
	t_color3 color;
	t_set3	set3;

	slice_set(src, &set3);
	valid_digit_set(&set3);
	color.x = ft_atol(set3.src1);
	color.y = ft_atol(set3.src2);
	color.z = ft_atol(set3.src3);
	if (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255 || color.z < 0 || color.z > 255)
		exit_print();
	return (color);
}

t_point3 get_point(char *src)
{
	t_point3 point;
	t_set3	set3;

	slice_set(src, &set3);
	valid_decimal_set(&set3);
	point.x = ft_atod(set3.src1);
	point.y = ft_atod(set3.src2);
	point.z = ft_atod(set3.src3);
	return (point);
}

t_vec3 get_vector(char *src)
{
	t_vec3 vec;
	t_set3	set3;

	slice_set(src, &set3);
	valid_decimal_set(&set3);
	vec.x = ft_atod(set3.src1);
	vec.y = ft_atod(set3.src2);
	vec.z = ft_atod(set3.src3);
	if (vec.x < -1.0 || vec.x > 1.0 || vec.y < -1.0 || vec.y > 1.0 || vec.z < -1.0 || vec.z > 1.0)
		exit_print();
	return (vec);
}

double get_FOV(char *src)
{
	double	ret;

	valid_decimal(src);
	ret = ft_atod(src);
	if (ret < 0.0 || ret > 180.0)
		exit_print();
	return (ret);
}

void parse_ambient(char *src, t_parse *parse)
{
	parse->A.rate = get_rate(src);
	parse->A.color = get_color(skip_whitespace(src));
}

void parse_camera(char *src, t_parse *parse)
{
	parse->C.view_point = get_point(src);
	parse->C.normal = get_vector(skip_whitespace(src));
	parse->C.FOV = get_FOV(skip_whitespace(src));
}

void parse_light(char *src, t_parse *parse)
{
	parse->L.light_point = get_point(src);
	parse->L.bright_rate = get_rate(skip_whitespace(src));
}

void parse_line(char *src, t_parse *parse)
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

char *read_line(char *line, t_parse *parse)
{
	char *ret;
	char *tmp;

	ret = find_char(line, '\n');
	if (ret == line)
		return (ret + 1);
	tmp = (char *)malloc(sizeof(char) * (ret - line + 1));
	ft_strlcpy(tmp, line, tmp - line);
	parse_line(tmp, parse);
	free(tmp);
	return (ret + 1);
}

void valid_contents(char *file_content, t_parse *parse)
{
	char *tmp;

	tmp = read_line(file_content, parse);
	while (tmp)
	{
		tmp = read_line(tmp, parse);
	}
	free(file_content);
}

void parsing(int argc, char **argv, t_parse *parse)
{
	valid_argument(argc);
	valid_file(argv[1]);
	valid_contents(open_and_read(argv[1]), parse);
}