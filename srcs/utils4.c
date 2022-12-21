/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:02:02 by junhjeon          #+#    #+#             */
/*   Updated: 2022/12/21 22:26:03 by junhjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

// 벡터 * 스칼라 곱연산
t_vec3	vmult(t_vec3 vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}

// 벡터 축 값끼리 곱연산
t_vec3	vmult_(t_vec3 vec, t_vec3 vec2)
{
	vec.x *= vec2.x;
	vec.y *= vec2.y;
	vec.z *= vec2.z;
	return (vec);
}

// 벡터 스칼라 나누기
t_vec3	vdivide(t_vec3 vec, double t)
{
	vec.x *= 1 / t;
	vec.y *= 1 / t;
	vec.z *= 1 / t;
	return (vec);
}
