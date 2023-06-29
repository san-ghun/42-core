/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:43:11 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/29 23:44:36 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_dlst	**ft_arrtodlst(t_dlst *dlst[], char *arr[], int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_dlstadd_back(dlst, ft_dlstnew(ft_atoi(arr[i])));
		i++;
	}
	i = 0;
	while (i < len)
		free(arr[i++]);
	free(arr);
	ft_presort(dlst, len, 0);

	ft_dlstprint(dlst);
	return (dlst);
}

static int	ft_strtodlst(t_dlst *dlst[], char *argv[])
{
	int		i;
	int		len;
	char	tmp[1];
	char	str[DATA_SIZE];
	char	**arr;

	i = 0;
	ft_strlcpy(tmp, " ", 2);
	ft_strlcpy(str, "", 1);
	while (argv[++i] != NULL)
	{
		ft_strlcat(str, argv[i], ft_strlen(str) + ft_strlen(argv[i]) + 1);
		ft_strlcat(str, tmp, ft_strlen(str) + ft_strlen(tmp) + 1);
	}
	len = ft_split_size(str, ' ');
	arr = ft_split(str, ' ');
	if (ft_iserror(arr, len))
		return (0);
	dlst = ft_arrtodlst(dlst, arr, len);
	return (len);
}

int	main(int argc, char *argv[])
{
	int		len;
	t_dlst	*stack_a;
	t_dlst	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	len = ft_strtodlst(&stack_a, argv);
	ft_printf("len = %d\n", len);
	if (!stack_a)
		return (ft_error());
	ft_printf("is ordered: %d\n", ft_isordered(&stack_a));
	ft_printf("is sorted: %d\n", ft_issorted(&stack_a, len));
	ft_dlstclear(&stack_a);
	ft_dlstclear(&stack_b);

	ft_dlstprint(&stack_a);
	ft_dlstprint(&stack_b);
	return (0);
}
