/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:15:13 by sanghupa          #+#    #+#             */
/*   Updated: 2022/12/30 23:15:20 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "ft_printf.h"

// int	main(int ac, char **av)
int	main(void)
{
	int	c1;
	int c2;
	long long int lli;
	char buf1[100000] = {0, };
	char buf2[100000] = {0, };

	// const char *format = "This is test";
	// const char *format = "This is tes%b";
	// char testin = 't';

	// const char *format = "This is %cest";
	// char testin = 't';

	// const char *format = "Hello, %s to the string";
	// char *testin = "welcome";
	// char *testin = NULL;

	// const char *format = "%p";
	// int testin = 0;
	// int testin = -1;
	// long testin = LONG_MAX;
	// long long testin = LLONG_MIN;
	// char *testin = "";
	// void *testin = (void *)12231;
	// void *testin = (void *)-12231;

	// const char *format = "%d";
	// const char *format = "%i";
	// int testin = -2147483648;
	// int testin = 21474;

	// const char *format = "%u";
	// unsigned int testin = 0;
	// unsigned int testin = 4294967295;
	// long long testin = LLONG_MAX;
	// long long testin = LLONG_MIN;

	const char *format = "%x";
	// const char *format = "%X";
	// int testin = 16782;
	// int testin = -1;
	long testin = -192883;
	// long testin = -9223372036854775807;
	// long long testin = LLONG_MAX;
	// long long testin = LLONG_MIN;

	// const char *format = "100%%";
	// int testin = 1;

	// const char *format = "%042.1d";
	// int testin = 42;

	printf("-- call ft_printf() --\n");
	c1 = ft_printf(format, testin);
	printf("\n----------------------\n");
	printf("$\n[ft_printf - count] : %d\n", c1);
	printf("");
	printf("\n-- call printf() --\n");
	c2 = printf(format, testin);
	printf("\n-------------------\n");
	printf("$\n[printf - count] : %d\n", c2);

	return (0);
}
