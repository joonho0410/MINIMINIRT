/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:55:55 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/02 19:57:14 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	write_color(t_color3 pixel_color)
{
	printf("%d %d %d\n", (int)(255.999 * pixel_color.x),
			(int)(255.999 * pixel_color.y),
			(int)(255.999 * pixel_color.z));
}
