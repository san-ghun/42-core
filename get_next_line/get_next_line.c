/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:22:56 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/21 00:23:56 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief return a line read from a file descriptor `fd`.
/// @param fd the file descriptor to read from.
/// @return read line if correctly behave, 
/// or a NULL if there is nothing else to read, or an error occurred.
char	*get_next_line(int fd)
{
	size_t	i;
	char	*buf;
	int		trsh;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	trsh = read(fd, buf, BUFFER_SIZE);
	if (trsh == -1)
	{
		free(buf);
		return (NULL);
	}
	buf[trsh] = '\0';
	return (buf);
}

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	fd = open("./testfile/test_nN.txt", O_RDONLY);
	printf("called read(%d, buf, BUFFER_SIZE=%d)\n", fd, BUFFER_SIZE);
	line = get_next_line(fd);
	printf("line read: \n%s\n", line);
	lseek(fd, 5, SEEK_CUR);
	printf("%c", '\n');
	line = get_next_line(fd);
	printf("line read: \n%s\n", line);
	close(fd);
	return (0);
}
