/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:19:27 by seungsle          #+#    #+#             */
/*   Updated: 2022/12/21 09:04:31 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

char	*open_and_read(char *file_name)
{
	int		fd;
	off_t	file_size;
	char	*file_contents;
	ssize_t	bytes_read;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		perror_exit("Error: opening file");
	file_size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	file_contents = malloc((file_size + 1) * sizeof(char));
	if (file_contents == NULL)
		perror_exit("Error: malloc failed");
	bytes_read = read(fd, file_contents, file_size);
	if (bytes_read == -1)
		perror_exit("Error: reading from file");
	return (file_contents);
}

char	*read_line(char *line, t_parse *parse)
{
	char	*ret;
	char	*tmp;
	int		size;

	ret = find_char(line, '\n');
	if (ret == line)
		return (ret + 1);
	if (ret != NULL)
		size = ret - line + 1;
	else
		size = ft_strlen(line) + 1;
	tmp = (char *)malloc(sizeof(char) * (size));
	ft_strlcpy(tmp, line, size);
	parse_line(tmp, parse);
	free(tmp);
	return (ret + 1);
}
