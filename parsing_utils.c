/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:20:17 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/18 21:25:24 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"

int	is_whitespace(char c)
{
  return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	temp;

	i = 0;
	if (!dst && !(char *)src)
		return (0);
	temp = ft_strlen(src);
	if (!size)
		return (temp);
	while (i + 1 < size && (char)src[i])
	{
		dst[i] = (char)src[i];
		i++;
	}
	dst[i] = '\0';
	return (temp);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_u;
	unsigned char	*s2_u;

	i = 0;
	s1_u = (unsigned char *)s1;
	s2_u = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*s1_u && *s2_u && i++ < n - 1)
	{
		if (*s1_u != *s2_u)
		{
			return (*s1_u - *s2_u);
		}
		s1_u++;
		s2_u++;
	}
	return (*s1_u - *s2_u);
}

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