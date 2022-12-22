/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:26:56 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/22 12:32:57 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# define KEY_ESC				53

# define KEY_ONE				18
# define KEY_TWO				19
# define KEY_THREE				20
# define KEY_FOUR				21
# define KEY_FIVE				22
# define KEY_SIX				23

# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_DOWN				125
# define KEY_UP					126

# define KEY_P					35
# define KEY_M					46

# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

int	listener(int keycode, void *param);

#endif