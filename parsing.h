/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:36:56 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/19 09:20:17 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H_
# define PARSING_H_

#include "structures.h"
#include "scene.h"
#include "util.h"

typedef struct s_parse t_parse;
typedef struct s_ambient_p t_ambient_p;
typedef struct s_camera_p t_camera_p;
typedef struct s_light_p t_light_p;
typedef struct s_sphere_p t_sphere_p;
typedef struct s_plain_p t_plain_p;
typedef struct s_cylinder_p t_cylinder_p;
typedef struct s_set3 t_set3;

struct s_ambient_p {
	double rate;
	t_color3 color;
};

struct s_camera_p {
	t_point3 view_point;
	t_vec3 normal;
	double FOV;
};

struct s_light_p {
	t_point3 light_point;
	double bright_rate;
};

struct s_sphere_p {
	t_point3 center;
	double diameter;
	t_color3 color;
};

struct s_plain_p {
	t_point3 coordinates;
	t_vec3 normal;
	t_color3 color;
};

struct s_cylinder_p {
	t_point3 coordinates;
	t_vec3 noraml;
	double diameter;
	double height;
	t_color3 color;
};

struct s_objects_p {
	int size;
	void *object;
};

struct s_parse {
	t_ambient_p A;
	t_camera_p C;
	t_light_p L;
	t_object *ob_p;
};

struct s_set3 {
	char *src1;
	char *src2;
	char *src3;
};

t_scene *parsing(int argc, char **argv, t_parse *parse);

#endif