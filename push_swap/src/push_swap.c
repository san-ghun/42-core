/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:43:11 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/14 12:07:41 by sanghupa         ###   ########.fr       */
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

static int	*make_lens(int len)
{
	static int	array[3] = {0, 0, 0};

	array[0] = len;
	return (array);
}

int	sort(t_dlst *stack_a[], t_dlst *stack_b[], int len, int *lens)
{
	if (len == 2)
		sort_two(stack_a, 'a');
	if (len == 3)
		sort_three(stack_a, 'a');
	if (len == 4)
		sort_four(stack_a, stack_b, lens, 0);
	if (len == 5)
		sort_five(stack_a, stack_b, lens);
	if (len >= 6)
	{
		preprocess(stack_a, stack_b, len, lens);
		sort_small(stack_a, stack_b, len, lens);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int		len;
	int		*lens;
	t_dlst	*stack_a;
	t_dlst	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	len = ft_strtodlst(&stack_a, argv);
	if (!stack_a)
		return (ft_error());
	lens = make_lens(len);
	if (ft_issorted(&stack_a, len))
	{
		ft_dlstclear(&stack_a);
		ft_dlstclear(&stack_b);
		return (0);
	}
	sort(&stack_a, &stack_b, len, lens);
	ft_dlstclear(&stack_a);
	ft_dlstclear(&stack_b);
	return (0);
}
