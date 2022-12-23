/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:22:56 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/23 18:18:44 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "get_next_line.h"

char	*ft_update_bufs(char *bufs)
{
	size_t	i;
	size_t	j;
	char	*updated;

	if (!bufs)
		return (NULL);
	i = 0;
	while (bufs[i] && bufs[i] != '\n')
		i++;
	updated = (char *)malloc(sizeof(char) * (ft_strlen_gnl(bufs) - i + 1));
	if (!updated)
		return (NULL);
	i++;
	j = 0;
	while (bufs[i])
		updated[j++] = bufs[i++];
	bufs = updated;
	free(updated);
	return (bufs);
}

char	*ft_get_line(char *bufs)
{
	size_t	i;
	char	*line;

	if (!bufs)
		return (NULL);
	i = 0;
	while (bufs[i] && bufs[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (bufs[i] && bufs[i] != '\n')
	{
		line[i] = bufs[i];
		i++;
	}
	if (bufs[i] == '\n')
	{
		line[i] = bufs[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_add_bufs(int fd, char *bufs)
{
	char	*buf;
	int		byte_read;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	byte_read = 1;
	if (!bufs)
		bufs = NULL;
	while (!ft_strchr_gnl(bufs, '\n') && byte_read != 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[byte_read] = '\0';
		bufs = ft_strjoin_gnl(bufs, buf);
	}
	free(buf);
	return (bufs);
}

/// @brief return a line read from a file descriptor `fd`.
/// @param fd the file descriptor to read from.
/// @return read line if correctly behave, 
/// or a NULL if there is nothing else to read, or an error occurred.
char	*get_next_line(int fd)
{
	static char	*bufs;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bufs = ft_add_bufs(fd, bufs);
	if (!bufs)
		return (NULL);
	// printf("bufs before: %s\n", bufs);
	line = ft_get_line(bufs);
	// printf("bufs during: %s\n", bufs);
	bufs = ft_update_bufs(bufs);
	// printf("bufs after: %s\n", bufs);
	return (line);
}

// #include <fcntl.h>
// // #include <stdio.h>
// #include <string.h>
// int	main(int ac, char **av)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("./testfile/test_42N.txt", O_RDONLY);
// 	printf("called read(%d, buf, BUFFER_SIZE=%d)\n", fd, BUFFER_SIZE);
// 	line = get_next_line(fd);
// 	printf("line read: \n%s\n", line);
// 	// free(line);
// 	// lseek(fd, 5, SEEK_CUR);
// 	printf("%c", '\n');
// 	line = get_next_line(fd);
// 	printf("line read: \n%s\n", line);
// 	free(line);
// 	close(fd);
// 	return (0);
// }
