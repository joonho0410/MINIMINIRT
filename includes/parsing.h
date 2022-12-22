/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:36:56 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/22 12:51:49 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "./structures.h"
# include "./utils.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_parse		t_parse;
typedef struct s_ambient_p	t_ambient_p;
typedef struct s_camera_p	t_camera_p;
typedef struct s_light_p	t_light_p;
typedef struct s_sphere_p	t_sphere_p;
typedef struct s_plain_p	t_plain_p;
typedef struct s_cylinder_p	t_cylinder_p;
typedef struct s_set3		t_set3;

struct s_ambient_p {
	int			updated;
	double		rate;
	t_color3	color;
};

struct s_camera_p {
	int			updated;
	t_point3	view_point;
	t_vec3		normal;
	double		fov;
};

struct s_light_p {
	int			updated;
	t_point3	light_point;
	double		bright_rate;
};

struct s_sphere_p {
	t_point3	center;
	double		diameter;
	t_color3	color;
};

struct s_plain_p {
	t_point3	coordinates;
	t_vec3		normal;
	t_color3	color;
};

struct s_cylinder_p {
	t_point3	coordinates;
	t_vec3		noraml;
	double		diameter;
	double		height;
	t_color3	color;
};

struct s_objects_p {
	int			size;
	void		*object;
};

struct s_parse {
	t_ambient_p	a;
	t_camera_p	c;
	t_light_p	l;
	t_object	*ob_p;
};

struct s_set3 {
	char		*src1;
	char		*src2;
	char		*src3;
};

void		valid_argument(int argc);
void		valid_file(char *str);
void		valid_contents(char *file_content, t_parse *parse);

void		exit_print(void);
void		perror_exit(char *str);

char		*open_and_read(char *file_name);
char		*read_line(char *line, t_parse *parse);

void		parse_sphere(char *src, t_parse *parse);
void		parse_plane(char *src, t_parse *parse);
void		parse_cylinder(char *src, t_parse *parse);

void		parse_ambient(char *src, t_parse *parse);
void		parse_camera(char *src, t_parse *parse);
void		parse_light(char *src, t_parse *parse);

void		valid_decimal_set(t_set3 *set3);
void		valid_digit_set(t_set3 *set3);
void		slice_set(char *src, t_set3 *set3);
double		get_double(char *src);

double		get_rate(char *src);
t_color3	get_color(char *src);
t_point3	get_point(char *src);
t_vec3		get_vector(char *src);
double		get_fov(char *src);

int			valid_identifier(char *src, char *c, int n);
void		valid_decimal(char *src);
void		valid_digit(char *src);

char		*find_char(char *str, char find);
char		*skip_whitespace(char *src);

int			is_digit(char c);
int			is_dot(char c);
int			is_empty(char *str);
void		divide_3(t_ambient_p *a);
t_color3	zero_to_one(t_color3 color);

int			is_whitespace(char c);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

double		ft_atod(char *str);
long long	ft_atol(const char *str);

void		parse_line(char *src, t_parse *parse);
t_scene		*parsing(int argc, char **argv, t_parse *parse);

t_scene		*scene_init(t_parse *parse);

#endif