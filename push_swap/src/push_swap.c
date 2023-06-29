/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:43:11 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/29 12:05:40 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_dlst	**ft_strtodlst(t_dlst *dlst[], char *argv[])
{
	int		i;
	int		len;
	char	tmp[1];
	char	*str;
	char	**arr;

	i = 0;
	ft_strlcpy(tmp, " ", 2);
	str = NULL;
	ft_printf("str to arr\n");
	while (argv[++i] != NULL)
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, tmp);
	}
	len = ft_split_size(str, ' ');
	arr = ft_split(str, ' ');
	free(str);

	i = 0;
	while (i < len)
	{
		ft_printf("value is %s\n", arr[i]);
		i++;
	}
	
	if (ft_iserror(arr))
	{
		i = 0;
		while (i < len)
			free(arr[i++]);
		free(arr);
		return (NULL);
	}

	i = 0;
	ft_printf("arr to dlst\n");
	while (i < len)
	{
		ft_dlstadd_back(dlst, ft_dlstnew(ft_atoi(arr[i])));
		ft_printf("int: %d\n", ft_atoi(arr[i]));
		ft_printf("str: %s\n", arr[i]);
		i++;
	}

	i = 0;
	while (i < len)
		free(arr[i++]);
	free(arr);

	ft_printf("\n");
	ft_dlstprint(dlst);
	return (dlst);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_dlst	**stack_a = NULL;
	t_dlst	**stack_b = NULL;

	if (argc == 1)
		return (0);
	i = 0;
	*stack_a = NULL;
	*stack_b = NULL;
	stack_a = ft_strtodlst(stack_a, argv);
	if (!stack_a)
		return (ft_error());
	ft_dlstclear(stack_a);
	ft_dlstclear(stack_b);
	ft_dlstprint(stack_a);
	ft_dlstprint(stack_b);
	return (0);
}
