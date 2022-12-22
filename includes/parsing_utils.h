/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:20:15 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/22 12:45:04 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_UTILS_H
# define PARSING_UTILS_H

# include <stdlib.h>
# include <math.h>

typedef struct s_atod	t_atod;

struct s_atod {
	double		decimal;
	long long	integer;
};

int			is_whitespace(char c);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		ft_atod(char *str);
long long	ft_atol(const char *str);

#endif