/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:20:26 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/21 07:29:25 by seungsle         ###   ########.fr       */
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

// t_scene *scene_init(t_parse *parse)
// {
// 	t_scene		*scene;
// 	t_object	*world;
// 	t_object	*lights;
// 	double		ka;

// 	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
// 		return (0);
// 	scene->canvas = canvas(400, 300);
// 	scene->camera = camera(&scene->canvas, point3(0, 0, 20));
// 	//world = object(SP, sphere(point3(0, 0, -20), 6), color3(0, 0, 1));
//     world = object(PL, plain(point3(0, 0, -20), point3(0, 0, 1)), color3(0.3, 0.3, 0.3)); // world 에 구1 추가
//     //oadd(&world, object(SP, sphere(point3(0, -5, -10), 2), color3(0, 0.5, 0))); // world 에 구2 추가
//     oadd(&world, object(CY, cylinder(point3(5, 0, -20), vec3(0, 0, 1), 10, 10), color3(0.3, 0, 0))); // world 에 구3 추가
// 	//oadd(&world, object(SP, cylinder(point3(0, 0, -12), vec3(0, 1, 0), 2, 2), color3(0, 0, 0.5)));
//     scene->world = world;
// 	lights = object(LIGHT_POINT, light_point(point3(0, 20, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0));
// 	scene->light = lights;
// 	scene->ambient = vmult(parse->A.color, parse->A.rate);
//     rotate_world(scene, world);
// 	return (scene);
// }

void mlx_window_init(t_scene *scene, t_mlx_data *mlx_data)
{
    mlx_data->mlx.mlx_ptr = NULL;
    mlx_data->mlx.win = NULL;
   	mlx_data->img.img_ptr = NULL;
    mlx_data->img.data = NULL;
    mlx_data->rgb.r = 0;
    mlx_data->rgb.g = 0;
    mlx_data->rgb.b = 0;
    mlx_data->scene = scene;
	// t_scene		*scene;
	// t_object	*world;
	// t_object	*lights;
	// double		ka;

	// if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
	// 	return (0);
	// scene->canvas = canvas(400, 300);
	// scene->camera = camera(&scene->canvas, point3(0, 0, 50));
	// //world = object(SP, sphere(point3(0, 0, -20), 6), color3(0, 0, 1));
    // world = object(PL, plain(point3(0, 0, -20), point3(0, 0, 1)), color3(1, 0.3, 0.3)); // world 에 구1 추가
    // //oadd(&world, object(SP, sphere(point3(0, 0, -10), 10), color3(0.3, 0.3, 1))); // world 에 구2 추가
    // oadd(&world, object(CY, cylinder(point3(0, 0, -10), vec3(0, 0, 1), 10, 10), color3(0.3, 0.3, 1))); // world 에 구3 추가
	// //oadd(&world, object(SP, cylinder(point3(0, 0, -12), vec3(0, 1, 0), 2, 2), color3(0, 0, 0.5)));
    // scene->world = world;
	// lights = object(LIGHT_POINT, light_point(point3(0, 0, 30), color3(1, 1, 1), 0.5), color3(0, 0, 0));
	// scene->light = lights;
	// ka = 0.5;
	// scene->ambient = vmult(color3(1, 1, 1), ka);
    // rotate_world(scene, world);
	// return (scene);
}

void print_color(t_vec3 *vec)
{
    printf("(%f, %f, %f)\n", vec->x, vec->y, vec->z);
}

void print_parsing(t_parse *parse)
{
    printf("A : color > ");
    print_color(&parse->A.color);
    printf("A : rate > %f\n", parse->A.rate);
    printf("C : FOV > %f\n", parse->C.FOV);
    printf("C : normal > ");
    print_color(&parse->C.normal);
    printf("C : view point > ");
    print_color(&parse->C.view_point);
    printf("L : rate > %f\n", parse->L.bright_rate);
    printf("L : light point > ");
    print_color(&parse->L.light_point);
}

int main(int argc, char **argv)
{
    // int         i;
    // int         j;
    // double      u;
    // double      v;

    // t_color3    pixel_color;
	t_scene		*scene;
    t_mlx_data  mlx_data;
    t_parse parse;
    // t_object ob_p;
    scene = parsing(argc, argv, &parse);
    print_parsing(&parse);
    // scene = scene_init(&parse);

    // 랜더링
    // P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
    /* * * * 수정 * * * */
    printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
    mlx_window_init(scene, &mlx_data);
    execute(scene, &mlx_data);
    // j = scene->canvas.height - 1;
    // while (j >= 0)
    // {
    //     i = 0;
    //     while (i < scene->canvas.width)
    //     {
    //         u = (double)i / (scene->canvas.width - 1);
    //         v = (double)j / (scene->canvas.height - 1);
    //         scene->ray = ray_primary(&scene->camera, u, v);
    //         pixel_color = ray_color(scene);
    //         write_color(pixel_color);
    //         ++i;
    //     }
    //     --j;
    // }
}
