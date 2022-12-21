/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_basic_validation_check.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:17:24 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/21 08:58:28 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	valid_argument(int argc)
{
	if (argc != 2)
		exit_print();
}

void	valid_file(char *str)
{
	char	*temp;

	temp = find_char(str, '.');
	if (temp == NULL)
		exit_print();
	temp = find_char(temp + 1, '.');
	if (temp != NULL)
		exit_print();
}

void	valid_contents(char *file_content, t_parse *parse)
{
	char	*tmp;

	tmp = read_line(file_content, parse);
	while (tmp && ft_strlen(tmp))
	{
		tmp = read_line(tmp, parse);
	}
	free(file_content);
}
