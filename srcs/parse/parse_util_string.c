/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:16:38 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/21 09:03:13 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

char	*find_char(char *str, char find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == find)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*skip_whitespace(char *src)
{
	int	i;

	i = 0;
	while (src[i] && !is_whitespace(src[i]))
		i++;
	while (src[i] && is_whitespace(src[i]))
		i++;
	return (&src[i]);
}
