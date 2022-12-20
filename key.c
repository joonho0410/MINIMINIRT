/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:27:09 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/20 11:45:11 by seungsle         ###   ########.fr       */
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
	{
		if (data->scene->camera.orig.y + 0.1 > 1)
			data->scene->camera.orig.y = 1;
		else
			data->scene->camera.orig.y += 0.1;
	}
	else if (keycode == KEY_DOWN)
	{
		if (data->scene->camera.orig.y - 0.1 < -1)
			data->scene->camera.orig.y = -1;
		else
			data->scene->camera.orig.y -= 0.1;
	}
	else if (keycode == KEY_LEFT)
	{
		if (data->scene->camera.orig.x + 0.1 > 1)
			data->scene->camera.orig.x = 1;
		else
			data->scene->camera.orig.x += 0.1;
	}
	else if (keycode == KEY_RIGHT)
	{
		if (data->scene->camera.orig.x - 0.1 < -1)
			data->scene->camera.orig.x = -1;
		else
			data->scene->camera.orig.x -= 0.1;
	}
	return ;
}

// void	key_3(int keycode, t_mlx_data *data)
// {
// 	if (keycode == KEY_ONE)
// 		data->rgb.set_r += 5;
// 	else if (keycode == KEY_TWO)
// 		data->rgb.set_g += 5;
// 	else if (keycode == KEY_THREE)
// 		data->rgb.set_b += 5;
// 	return ;
// }

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
	// key_3(keycode, data);
	// key_4(keycode, data);
	loop(data->scene, data);
	return (0);
}
