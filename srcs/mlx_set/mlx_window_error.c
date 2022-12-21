/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:07:33 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/21 09:09:53 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_window.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	return ;
}

void	error_detected(int error)
{
	if (error == MLX_INIT_ERROR)
		ft_putstr_fd("Error : mlx_init() failed", 1);
	else if (error == MLX_NEW_WINDOW_ERROR)
		ft_putstr_fd("Error : mlx_new_window() failed", 1);
	else if (error == MLX_NEW_IMAGE_ERROR)
		ft_putstr_fd("Error : mlx_new_image() failed", 1);
	else if (error == MLX_GET_DATA_ADDR_ERROR)
		ft_putstr_fd("Error : mlx_get_data_addr() failed", 1);
	exit(1);
}
