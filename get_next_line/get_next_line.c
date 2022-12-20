/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:22:56 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/20 12:28:20 by sanghupa         ###   ########.fr       */
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

	fd = open("", O_RDONLY);
	line = get_next_line(fd);

	strcpy(src, "This is an example.");
	res_org = strchr(src, ch);
	res_ft = ft_strchr(src, ch);
	printf("Origin string is |%s| \n", src);
	printf("src: String after |%c| is - |%s|\n", ch, res_org);
	printf("ft_: String after |%c| is - |%s|\n\n", ch, res_ft);
	return (0);
}