/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:20:15 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/18 18:56:54 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_UTILS_H_
#define PARSING_UTILS_H_

#include <stdlib.h>

int is_whitespace(char c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif