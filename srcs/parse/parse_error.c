/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:14:28 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/21 08:58:39 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	exit_print(void)
{
	printf("Error\n");
	exit(1);
}

void	perror_exit(char *str)
{
	perror(str);
	exit(1);
}
