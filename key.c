/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:27:09 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/20 12:09:19 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"
#include "mlx_window.h"

void	key_1(int keycode)
{
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
}

void	key_2(int keycode, t_mlx_data *data)
{
	if (keycode == KEY_UP)
		data->scene->camera.orig.y += 0.1;
	else if (keycode == KEY_DOWN)
		data->scene->camera.orig.y -= 0.1;
	else if (keycode == KEY_LEFT)
		data->scene->camera.orig.x += 0.1;
	else if (keycode == KEY_RIGHT)
		data->scene->camera.orig.x -= 0.1;
	else if (keycode == KEY_P)
		data->scene->camera.orig.z += 0.1;
	else if (keycode == KEY_M)
		data->scene->camera.orig.z -= 0.1;
	return ;
}

void	key_3(int keycode, t_mlx_data *data)
{
	if (keycode == KEY_ONE)
	{
		data->scene->c_normal.z = 1;
	}
	else if (keycode == KEY_TWO)
	{
		data->scene->c_normal.z = -1;
	}
	else if (keycode == KEY_W)
	{
		if (data->scene->c_normal.y + 0.1 > 1)
			data->scene->c_normal.y = 1;
		else
			data->scene->c_normal.y += 0.1;
	}
	else if (keycode == KEY_S)
	{
		if (data->scene->c_normal.y - 0.1 < -1)
			data->scene->c_normal.y = -1;
		else
			data->scene->c_normal.y -= 0.1;
	}
	else if (keycode == KEY_A)
	{
		if (data->scene->c_normal.x + 0.1 > 1)
			data->scene->c_normal.x = 1;
		else
			data->scene->c_normal.x += 0.1;
	}
	else if (keycode == KEY_D)
	{
		if (data->scene->c_normal.x - 0.1 < -1)
			data->scene->c_normal.x = -1;
		else
			data->scene->c_normal.x -= 0.1;
	}
	return ;
}

// void	key_4(int keycode, t_mlx_data *data)
// {
// 	if (keycode == KEY_P)
// 		data->pxl.last_zoom *= 1.1;
// 	else if (keycode == KEY_M)
// 		data->pxl.last_zoom *= 0.9;
// 	if (data->loop_mul < data->pxl.last_zoom / 300)
// 	{
// 		data->loop_mul++;
// 		data->loop_max = 42 * (data->loop_mul + 1);
// 	}
// }

int	listener(int keycode, void *param)
{
	t_mlx_data	*data;

	data = (t_mlx_data *)param;
	key_1(keycode);
	key_2(keycode, data);
	key_3(keycode, data);
	// key_4(keycode, data);
	loop(data->scene, data);
	return (0);
}