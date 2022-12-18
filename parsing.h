/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:36:56 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/18 15:33:10 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H_
# define PARSING_H_

#include "structures.h"

typedef struct s_parse t_parse;
typedef struct s_ambient t_ambient;
typedef struct s_camera t_camera;
typedef struct s_light t_light;
typedef struct s_objects t_objects;
typedef struct s_sphere t_sphere;
typedef struct s_plain t_plain;
typedef struct s_cylinder t_cylinder;

struct s_ambient {
	double rate;
	t_color3 color;
};

struct s_camera {
	t_point3 view_point;
	t_vec3 normal;
	double FOV;
};

struct s_light {
	t_point3 light_point;
	double bright_rate;
};

struct s_sphere {
	t_point3 center;
	double diameter;
	t_color3 color;
};

struct s_plain {
	t_point3 coordinates;
	t_vec3 normal;
	t_color3 color;
};

struct s_cylinder {
	t_point3 coordinates;
	t_vec3 noraml;
	double diameter;
	double height;
	t_color3 color;
};

struct s_objects {
	int size;
	void *object;
};

struct s_parse {
	t_ambient A;
	
};

void parsing(int argc, char **argv);

#endif