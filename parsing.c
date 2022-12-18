/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:33:15 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/18 19:38:55 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "parsing_utils.h"
#include <stdio.h>
#include <fcntl.h>

void exit_print(void)
{
	printf("Error\n");
	exit(1);
}

void perror_exit(char *str)
{
	perror(str);
	exit(1);
}

char *find_char(char *str, char find)
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

void valid_argument(int argc)
{
	if (argc != 2)
		exit_print();
}

void valid_file(char *str)
{
	char *temp;

	temp = find_char(str, '.');
	if (temp == NULL)
		exit_print();
	temp = find_char(temp, '.');
	if (temp != NULL)
		exit_print();
}

char *open_and_read(char *file_name)
{
	int fd;
	off_t file_size;
	char *file_contents;
	ssize_t bytes_read;
	
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		perror_exit("Error: opening file");
	file_size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	file_contents = malloc(file_size * sizeof(char));
	if (file_contents == NULL)
		perror_exit("Error: malloc failed");
	bytes_read = read(fd, file_contents, file_size);
	if (bytes_read == -1)
		perror_exit("Error: reading from file");
	return (file_contents);
}

int valid_identifier(char *src, char *c, int n)
{
	if (ft_strncmp(src, c, n) == 0)
	{
		if (is_whitespace(src[n]))
			return (TRUE);
	}
	return (FALSE);
}

char *skip_whitespace(char *src)
{
	int	i;

	i = 0;
	while (src[i] && is_whitespace(src[i]))
		i++;
	return (&src[i]);
}

void parse_line(char *src, t_parse *parse)
{
	if (valid_identifier(src, "A", 1))
		parse_ambient(skip_whitespace(src), parse);
	else if (valid_identifier(src, "C", 1))
		parse_camera(skip_whitespace(src), parse);
	else if (valid_identifier(src, "L", 1))
		parse_light(skip_whitespace(src), parse);
	else if (valid_identifier(src, "sp", 2))
		parse_sphere(skip_whitespace(src), parse);
	else if (valid_identifier(src, "pl", 2))
		parse_plane(skip_whitespace(src), parse);
	else if (valid_identifier(src, "cy", 2))
		parse_cylinder(skip_whitespace(src), parse);
	else
		exit_print();
}

char *read_line(char *line, t_parse *parse)
{
	char *ret;
	char *tmp;

	ret = find_char(line, '\n');
	if (ret == line)
		return (ret + 1);
	tmp = (char *)malloc(sizeof(char) * (ret - line + 1));
	ft_strlcpy(tmp, line, tmp - line);
	parse_line(tmp, parse);
	free(tmp);
	return (ret + 1);
}

void valid_contents(char *file_content, t_parse *parse)
{
	char *tmp;

	tmp = read_line(file_content, parse);
	while (tmp)
	{
		tmp = read_line(tmp, parse);
	}
	free(file_content);
}

void parsing(int argc, char **argv, t_parse *parse)
{
	valid_argument(argc);
	valid_file(argv[1]);
	valid_contents(open_and_read(argv[1]), parse);
}