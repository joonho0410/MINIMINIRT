/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:40:58 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/22 15:00:23 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_window.h"
#include "../../includes/trace.h"
#include "../../includes/print.h"
#include "../../includes/key.h"
#include "../../includes/rotate.h"

#define WIN_WIDTH 400
#define WIN_HEIGHT 300

int	press_x(t_mlx_data *ptr)
{
	mlx_destroy_window(ptr->mlx.mlx_ptr, ptr->mlx.win);
	exit(0);
	return (0);
}

void	put_color(t_mlx_data *data, t_img *img, int x, int y)
{
	int			offset;
	double		u;
	double		v;
	t_color3	pixel_color;

	u = (double)x / (data->scene->canvas.width - 1);
	v = (double)y / (data->scene->canvas.height - 1);
	data->scene->ray = ray_primary(&data->scene->camera, u, v);
	pixel_color = ray_color(data->scene);
	offset = (x * (img->bpp / 8)) + (y * img->size_l);
	img->data[offset] = (int)(255.999 * pixel_color.z);
	img->data[offset + 1] = (int)(255.999 * pixel_color.y);
	img->data[offset + 2] = (int)(255.999 * pixel_color.x);
	return ;
}

void	pxl_to_img(t_scene *scene, t_mlx_data *data)
{
	int	i;
	int	j;

	rotate_world(data->scene, data->scene->world);
	data->img.data = (char *)mlx_get_data_addr(data->img.img_ptr, \
	&data->img.bpp, &data->img.size_l, &data->img.endian);
	j = scene->canvas.height - 1;
	if (data->img.data)
	{
		while (j >= 0)
		{
			i = 0;
			while (i < scene->canvas.width)
			{
				put_color(data, &(data->img), i, j);
				++i;
			}
			--j;
		}
	}
	else
		error_detected(MLX_GET_DATA_ADDR_ERROR);
	return ;
}

void	loop(t_scene *scene, t_mlx_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx.mlx_ptr, WIN_WIDTH, \
	WIN_HEIGHT);
	if (data->img.img_ptr)
	{
		pxl_to_img(scene, data);
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win, \
		data->img.img_ptr, 0, 0);
		mlx_destroy_image(data->mlx.mlx_ptr, data->img.img_ptr);
	}
	else
		error_detected(MLX_NEW_IMAGE_ERROR);
}

void	execute(t_scene *scene, t_mlx_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	if (data->mlx.mlx_ptr)
	{
		data->mlx.win = mlx_new_window(data->mlx.mlx_ptr, WIN_WIDTH, \
		WIN_HEIGHT, "fractol");
		if (data->mlx.win)
		{
			loop(scene, data);
			mlx_key_hook(data->mlx.win, listener, (void *)data);
			mlx_hook(data->mlx.win, 17, 0, &press_x, data);
			mlx_loop(data->mlx.mlx_ptr);
		}
		else
			error_detected(MLX_NEW_WINDOW_ERROR);
	}
	else
		error_detected(MLX_INIT_ERROR);
}
