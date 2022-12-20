/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:22:56 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/20 16:14:44 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief return a line read from a file descriptor `fd`.
/// @param fd the file descriptor to read from.
/// @return read line if correctly behave, 
/// or a NULL if there is nothing else to read, or an error occurred.
char	*get_next_line(int fd)
{
	return (NULL);
}

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	buf[20];   // BUFFER_SIZE?
	size_t	nbytes;
	int		trsh;

	fd = open("./testfile/test_nN.txt", O_RDONLY);
	line = get_next_line(fd);
	nbytes = sizeof(buf);
	trsh = read(fd, buf, nbytes);

	printf("called read(%d, buf[20], sizeof(buf))\n", fd);
	printf("%d bytes were read.\n", trsh);
	buf[trsh] = '\0';
	printf("bytes are as follows: %s\n", buf);
	return (0);
}
