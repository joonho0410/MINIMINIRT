/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:20:26 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/21 08:01:58 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "scene.h"
#include "trace.h"
#include "structures.h"
#include "utils.h"
#include "print.h"
#include "rotate.h"
#include "parsing.h"
#include "mlx_window.h"

void	mlx_window_init(t_scene *scene, t_mlx_data *mlx_data)
{
	mlx_data->mlx.mlx_ptr = NULL;
	mlx_data->mlx.win = NULL;
	mlx_data->img.img_ptr = NULL;
	mlx_data->img.data = NULL;
	mlx_data->rgb.r = 0;
	mlx_data->rgb.g = 0;
	mlx_data->rgb.b = 0;
	mlx_data->scene = scene;
}

int	main(int argc, char **argv)
{
	t_scene		*scene;
	t_mlx_data	mlx_data;
	t_parse		parse;

	scene = parsing(argc, argv, &parse);
	printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
	mlx_window_init(scene, &mlx_data);
	execute(scene, &mlx_data);
}
