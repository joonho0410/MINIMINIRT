/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_validation_check.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:26:39 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/21 09:00:52 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	valid_identifier(char *src, char *c, int n)
{
	if (ft_strncmp(src, c, n) == 0)
	{
		if (is_whitespace(src[n]))
			return (TRUE);
	}
	return (FALSE);
}

void	valid_decimal(char *src)
{
	int	i;

	i = 0;
	if (src[i] == '-' || src[i] == '+')
		i++;
	if (is_whitespace(src[i]))
		exit_print();
	while (src[i] && !is_whitespace(src[i]) && !is_dot(src[i]))
	{
		if (!is_digit(src[i]) && !is_dot(src[i]))
			exit_print();
		i++;
	}
	if (src[i] && is_dot(src[i++]))
	{
		while (src[i] && !is_whitespace(src[i]))
		{
			if (!is_digit(src[i]))
				exit_print();
			i++;
		}
	}
}

void	valid_digit(char *src)
{
	int	i;

	i = 0;
	if (src[i] == '-' || src[i] == '+')
		i++;
	if (is_whitespace(src[i]))
		exit_print();
	while (src[i] && !is_whitespace(src[i]))
	{
		if (!is_digit(src[i]))
			exit_print();
		i++;
	}
}
