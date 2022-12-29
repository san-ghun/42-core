/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:15:13 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/29 15:22:29 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ft_printf.h"

// int	main(int ac, char **av)
int	main(void)
{
	int	c1;
	int c2;
	long long int lli;
	char buf1[100000] = {0, };
	char buf2[100000] = {0, };

	const char *format = "%042.1d";

	printf("-- call ft_printf() --\n");
	c1 = ft_printf(format, 42);
	printf("\n----------------------\n");
	printf("$\n[ft_printf - count] : %d\n", c1);
	printf("");
	printf("\n-- call printf() --\n");
	c2 = printf(format, 42);
	printf("\n-------------------\n");
	printf("$\n[printf - count] : %d\n", c2);

	return (0);
}
