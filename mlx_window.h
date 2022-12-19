/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:42:33 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/19 12:07:46 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WINDOW_H_
# define MLX_WINDOW_H_

# define MLX_INIT_ERROR			-1
# define MLX_NEW_WINDOW_ERROR	-2
# define MLX_NEW_IMAGE_ERROR	-3
# define MLX_GET_DATA_ADDR_ERROR	-4

#include "./mlx/mlx.h"
#include "scene.h"
#include <unistd.h>

typedef struct s_mlx_data t_mlx_data;
typedef struct s_img t_img;
typedef struct s_mlx t_mlx;
typedef struct s_rgb t_rgb;
typedef unsigned char			t_un_char;

struct s_rgb
{
	t_un_char	r;
	t_un_char	g;
	t_un_char	b;
};

struct s_img
{
	void		*img_ptr;
	char		*data;

	int			size_l;
	int			bpp;
	int			endian;
};

struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
};

struct s_mlx_data {
	t_img		img;
	t_mlx		mlx;
	t_rgb		rgb;
	t_scene		*scene;
};

void	execute(t_scene *scene, t_mlx_data *data);

#endif