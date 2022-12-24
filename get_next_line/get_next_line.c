/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:22:56 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/24 21:44:06 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update_bufs(char *bufs)
{
	size_t	i;
	size_t	j;
	char	*updated;

	i = 0;
	while (bufs[i] && bufs[i] != '\n')
		i++;
	if (bufs[i] == '\0')
	{
		free(bufs);
		return (NULL);
	}
	i += (bufs[i] == '\n');
	updated = (char *)malloc(sizeof(char) * (ft_strlen_gnl(bufs) - i + 1));
	if (!updated)
		return (NULL);
	j = 0;
	while (bufs[i + j])
	{
		updated[j] = bufs[i + j];
		j++;
	}
	updated[j] = '\0';
	free(bufs);
	return (updated);
}

char	*ft_get_line(char *bufs)
{
	size_t	i;
	char	*line;

	if (!bufs || (bufs[0] == '\0'))
		return (NULL);
	i = 0;
	while (bufs[i] && bufs[i] != '\n')
		i++;
	if (bufs[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (bufs[i] && bufs[i] != '\n')
	{
		line[i] = bufs[i];
		i++;
	}
	if (bufs[i] == '\n')
		line[i++] = '\n';
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
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bufs = ft_add_bufs(fd, bufs);
	if (!bufs)
		return (NULL);
	line = ft_get_line(bufs);
	bufs = ft_update_bufs(bufs);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// #include <string.h>
// char	*get_next_line_DEBUG(int fd)
// {
// 	static char	*bufs;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	printf("bufs init: %s(BUF_END)\n", bufs);
// 	bufs = ft_add_bufs(fd, bufs);
// 	if (!bufs)
// 		return (NULL);
// 	printf("bufs before read: %s(BUF_END)\n", bufs);
// 	line = ft_get_line(bufs);
// 	bufs = ft_update_bufs(bufs);
// 	printf("bufs after read: %s(BUF_END)\n", bufs);
// 	return (line);
// }
// int	main(int ac, char **av)
// {
// 	int		fd;
// 	int		lnumber;
// 	char	*line;

// 	fd = open("./testfile/test_tmp.txt", O_RDONLY);
// 	printf("called read(%d, buf, BUFFER_SIZE=%d)\n\n", fd, BUFFER_SIZE);
// 	lnumber = 0;
// 	line = "";
// 	while (line)
// 	{
// 		line = get_next_line_DEBUG(fd);
// 		if (line == NULL)
// 			lnumber = 0;
// 		else
// 			lnumber++;
// 		printf("%d: line read: %s(EOL)\n", lnumber, line);
// 		// free(line);
// 		// lseek(fd, 5, SEEK_CUR);
// 		printf("%c", '\n');
// 	}
// 	printf("EOF!");
// 	free(line);
// 	close(fd);
// 	return (0);
// }
