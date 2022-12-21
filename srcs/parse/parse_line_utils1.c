/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:28:26 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/21 09:04:05 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	valid_decimal_set(t_set3 *set3)
{
	valid_decimal(set3->src1);
	valid_decimal(set3->src2);
	valid_decimal(set3->src3);
}

void	valid_digit_set(t_set3 *set3)
{
	valid_digit(set3->src1);
	valid_digit(set3->src2);
	valid_digit(set3->src3);
}

void	slice_set(char *src, t_set3 *set3)
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;
	int		i;

	tmp1 = find_char(src, ',');
	tmp2 = find_char(tmp1 + 1, ',');
	i = 0;
	while (1)
	{
		if (!tmp2[i] || is_whitespace(tmp2[i]))
		{
			tmp3 = &tmp2[i];
			break ;
		}
		i++;
	}
	set3->src1 = (char *)malloc(sizeof(char) * ((tmp1 + 1) - src + 1));
	set3->src2 = (char *)malloc(sizeof(char) * (tmp2 - tmp1 + 1));
	set3->src3 = (char *)malloc(sizeof(char) * (tmp3 - tmp2 + 1));
	ft_strlcpy(set3->src1, src, (tmp1 + 1) - src);
	ft_strlcpy(set3->src2, tmp1 + 1, tmp2 - tmp1);
	ft_strlcpy(set3->src3, tmp2 + 1, tmp3 - tmp2);
}

double	get_double(char *src)
{
	double	ret;

	valid_decimal(src);
	ret = ft_atod(src);
	return (ret);
}
