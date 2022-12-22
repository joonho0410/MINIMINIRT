/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:20:26 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/22 14:53:10 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/scene.h"
#include "../includes/trace.h"
#include "../includes/structures.h"
#include "../includes/utils.h"
#include "../includes/print.h"
#include "../includes/rotate.h"
#include "../includes/parsing.h"
#include "../includes/mlx_window.h"

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
