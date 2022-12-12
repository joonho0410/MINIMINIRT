/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:20:26 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/07 20:52:23 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "scene.h"
#include "trace.h"
#include "structures.h"
#include "utils.h"
#include "print.h"

t_scene *scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;
	double		ka;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (0);
	scene->canvas = canvas(400, 300);
	scene->camera = camera(&scene->canvas, point3(10, 0, 10));
	//world = object(SP, sphere(point3(0, 0, -20), 6), color3(0, 0, 1));
    world = object(PL, plain(point3(0, 0, -20), point3(0, 0, -1)), color3(0.3, 0.3, 0.3)); // world 에 구1 추가
    //oadd(&world, object(SP, sphere(point3(0, -5, -10), 2), color3(0, 0.5, 0))); // world 에 구2 추가
    oadd(&world, object(CY, cylinder(point3(0, 0, -15), vec3(1, 0.5, 1), 10, 10), color3(0.3, 0, 0))); // world 에 구3 추가
	//oadd(&world, object(SP, cylinder(point3(0, 0, -12), vec3(0, 1, 0), 2, 2), color3(0, 0, 0.5)));
    scene->world = world;
	lights = object(LIGHT_POINT, light_point(point3(0, 0, 10), color3(1, 1, 1), 0.5), color3(0, 0, 0));
	scene->light = lights;
	ka = 0.5;
	scene->ambient = vmult(color3(1, 1, 1), ka);
	return (scene);
}

int main(void)
{
    int         i;
    int         j;
    double      u;
    double      v;

    t_color3    pixel_color;
	t_scene		*scene;
    scene = scene_init();

    // 랜더링
    // P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
    /* * * * 수정 * * * */
    printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
    j = scene->canvas.height - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < scene->canvas.width)
        {
            u = (double)i / (scene->canvas.width - 1);
            v = (double)j / (scene->canvas.height - 1);
            scene->ray = ray_primary(&scene->camera, u, v);
            pixel_color = ray_color(scene);
            write_color(pixel_color);
            ++i;
        }
        --j;
    }
}
