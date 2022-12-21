/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:58:44 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/21 23:21:25 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_vec3 t_vec3;
typedef struct	s_vec3 t_point3;
typedef struct	s_vec3 t_color3;
typedef struct	s_ray t_ray;
typedef struct	s_camera t_camera;
typedef struct	s_canvas t_canvas;
typedef struct	s_sphere t_sphere;
typedef struct	s_plain t_plain;
typedef struct	s_cylinder t_cylinder;
typedef struct	s_hit_record t_hit_record;
typedef struct	s_object	t_object;
typedef struct	s_light	t_light;
typedef struct	s_scene t_scene;
typedef struct	s_rotate t_rotate;
typedef struct	s_rotate_seta t_rotate_seta;
typedef struct	s_cal_cy_cap t_cal_cy_cap;
typedef struct	s_cal_cy t_cal_cy;
typedef struct	s_cal_sp t_cal_sp;
typedef struct	s_light_var t_light_var;
typedef struct	s_rotate_var t_rotate_var;



typedef int	t_bool;

# define FALSE 0
# define TRUE 1

typedef int		t_object_type;
# define SP 0
# define PL 1
# define CY 2

# define LIGHT_POINT 1
# define EPSILON 1e-6

# define LUMEN	3

struct s_vec3
{
	double x;
	double y;
	double z;
};

struct s_ray
{
	t_point3 orig;
	t_vec3	dir;
};

struct  s_camera
{
	t_point3	real_orig;
    t_point3    orig;  // 카메라 원점(위치)
    double      viewport_h; // 뷰포트 세로길이
    double      viewport_w; // 뷰포트 가로길이
    t_vec3      horizontal; // 수평길이 벡터
    t_vec3      vertical; // 수직길이 벡터
    double      focal_len; // focal length
    t_point3    left_bottom; // 왼쪽 아래 코너점
};

struct  s_canvas
{
    int     width; //canvas width
    int     height; //canvas height;
    double  aspect_ratio; //종횡비
};

struct s_sphere
{
	t_point3	real_center;
	t_point3	center;
	double		radius;
	double		radius2;
};

struct	s_plain
{
	t_point3	real_center;
	t_point3	center;
	t_vec3		real_normal;
	t_vec3		normal;
};

struct	s_cylinder
{
	t_point3	real_center;
	t_point3	center;
	t_vec3		real_normal;
	t_vec3		normal;
	double		radius;
	double		height;
};

struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	t_color3	albedo;
};

struct	s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	t_color3		albedo;
};

struct	s_light
{
	t_point3	real_origin;
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
};

struct	s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_color3		ambient;
	t_vec3			c_normal;
	t_ray			ray;
	t_hit_record	rec;
};

struct	s_rotate
{
	t_vec3	x;
	t_vec3	y;
	t_vec3	z;
};

struct	s_rotate_seta
{
	double	sinp;
	double	cosp;
	double	sint;
	double	cost;
};

struct s_cal_cy_cap
{
	double	root;
	double	nom;
	double	denom;
	double	diam;
};

struct s_cal_cy
{
	double	a;
	double	half_b;
	double	c;
	double	dis;
	double	root;
	double	sqrtd;
};

struct s_cal_sp
{
	double	a;
	double	half_b;
	double	c;
	double	dis;
	double	sqrtd;
	double	root;
	t_vec3	oc;
};

struct	s_light_var
{
	double		kd;
	double		spec;
	double		ksn;
	double		ks;
	double		brightness;
	double		light_len;
	t_color3	diffuse;
	t_vec3		light_dir;
	t_color3	specular;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	t_ray		light_ray;
};

struct	s_rotate_var
{
	t_vec3		move_p;
	t_vec3		camera_normal;
	t_vec3		rdup;
	t_vec3		horiz;
	t_vec3		vup;
	t_point3	newlights;
	t_light		*lights;
};

#endif
