/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:33:15 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/18 16:53:11 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
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

void parsing(int argc, char **argv)
{
	valid_argument(argc);
	valid_file(argv[1]);
	valid_contents(open_and_read(argv[1]));
}