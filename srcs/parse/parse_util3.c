/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:34:27 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/21 08:54:50 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing_utils.h"

void	get_decimal(char *str, double db_ret, long long p, t_atod *data)
{
	int		cnt;

	cnt = 0;
	while (*str >= '0' && *str <= '9')
	{
		db_ret *= 10;
		db_ret += (p * (*str - '0'));
		str++;
		cnt++;
	}
	db_ret /= pow(10, cnt);
	data->decimal = db_ret;
}

void	get_num(char *str, long long ret, long long p, t_atod *data)
{
	double	db_ret;

	while (*str >= '0' && *str <= '9')
	{
		ret *= 10;
		ret += (p * (*str - '0'));
		str++;
	}
	data->integer = ret;
	if (*str == '.')
	{
		db_ret = 0;
		str++;
		get_decimal(str, db_ret, p, data);
	}
}

double	ft_atod(char *str)
{
	long long	ret;
	long long	p;
	double		db_ret;
	t_atod		data;

	ret = 0;
	p = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			p *= -1;
		str++;
	}
	get_num(str, ret, p, &data);
	db_ret = data.integer + data.decimal;
	data.integer = 0;
	data.decimal = 0;
	return (db_ret);
}

long long	ft_atol(const char *str)
{
	long long	ret;
	long long	p;

	ret = 0;
	p = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			p *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret *= 10;
		ret += (p * (*str - '0'));
		str++;
	}
	return (ret);
}
