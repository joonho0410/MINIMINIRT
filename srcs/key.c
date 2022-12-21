/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:27:09 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/21 21:57:40 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/key.h"
#include "../includes/mlx_window.h"
#include "../includes/rotate.h"

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
		data->scene->camera.real_orig.y += 1;
	else if (keycode == KEY_DOWN)
		data->scene->camera.real_orig.y -= 1;
	else if (keycode == KEY_LEFT)
		data->scene->camera.real_orig.x += 1;
	else if (keycode == KEY_RIGHT)
		data->scene->camera.real_orig.x -= 1;
	else if (keycode == KEY_P)
		data->scene->camera.real_orig.z += 1;
	else if (keycode == KEY_M)
		data->scene->camera.real_orig.z -= 1;
	return ;
}

void	key_3(int keycode, t_mlx_data *data)
{
	if (keycode == KEY_ONE)
	{
		data->scene->c_normal.z += 0.1;
	}
	else if (keycode == KEY_TWO)
	{
		data->scene->c_normal.z -= 0.1;
	}
	else if (keycode == KEY_W)
	{
		data->scene->c_normal.y += 0.1;
	}
	else if (keycode == KEY_S)
	{
		data->scene->c_normal.y -= 0.1;
	}
	else if (keycode == KEY_A)
	{
		data->scene->c_normal.x += 0.1;
	}
	else if (keycode == KEY_D)
	{
		data->scene->c_normal.x -= 0.1;
	}
	return ;
}

int	listener(int keycode, void *param)
{
	t_mlx_data	*data;

	data = (t_mlx_data *)param;
	key_1(keycode);
	key_2(keycode, data);
	key_3(keycode, data);
	loop(data->scene, data);
	return (0);
}
