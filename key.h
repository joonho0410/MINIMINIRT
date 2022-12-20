/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:26:56 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/20 11:29:23 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H_
# define KEY_H_

# define KEY_ESC				53

# define KEY_ONE				18
# define KEY_TWO				19
# define KEY_THREE				20

# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_DOWN				125
# define KEY_UP					126

# define KEY_P					35
# define KEY_M					46

int	listener(int keycode, void *param);

#endif