#include "push_swap.h"

static t_dlst	**init_dlst(t_dlst *dlst[])
{
	ft_dlstadd_back(dlst, ft_dlstnew(1));
	ft_dlstadd_back(dlst, ft_dlstnew(2));
	ft_dlstadd_back(dlst, ft_dlstnew(3));
	ft_dlstadd_back(dlst, ft_dlstnew(4));
	return (dlst);
}

static void	test_dlst(void)
{
	t_dlst	**dlst;

	*dlst = NULL;

	dlst = init_dlst(dlst);
	ft_dlstprint(dlst);

	ft_dlstadd_front(dlst, ft_dlstnew(10));
	ft_dlstadd_front(dlst, ft_dlstnew(20));
	ft_dlstadd_front(dlst, ft_dlstnew(30));
	ft_dlstprint(dlst);

	ft_dlstdelone(dlst, ft_dlstget(dlst, 1));
	ft_dlstprint(dlst);
	ft_dlstdelone(dlst, ft_dlstget(dlst, 3));
	ft_dlstprint(dlst);

	ft_dlstdelone(dlst, ft_dlstget(dlst, 30));
	ft_dlstprint(dlst);
	ft_dlstdelone(dlst, ft_dlstget(dlst, 4));
	ft_dlstprint(dlst);

	ft_printf("head is %p\n", *dlst);
	ft_printf("tail is %p\n\n", ft_dlstlast(*dlst));

	ft_printf("%p\n", ft_dlstget(dlst, 20));
	ft_printf("%d\n", ft_dlstget(dlst, 20)->content);
	ft_printf("%d\n", ft_dlstget(dlst, 20)->index);
	ft_printf("%p\n", ft_dlstget(dlst, 20)->prev);
	ft_printf("%p\n\n", ft_dlstget(dlst, 20)->next);

	ft_printf("%p\n", ft_dlstget(dlst, 2));
	ft_printf("%d\n", ft_dlstget(dlst, 2)->content);
	ft_printf("%d\n", ft_dlstget(dlst, 2)->index);
	ft_printf("%p\n", ft_dlstget(dlst, 2)->prev);
	ft_printf("%p\n\n", ft_dlstget(dlst, 2)->next);

	ft_dlstprint(dlst);
	ft_dlstclear(dlst);
	ft_dlstprint(dlst);
	return ;
}

static void	test_stack(void)
{
	t_dlst	**dlst;
	t_dlst	*temp;

	*dlst = NULL;

	dlst = init_dlst(dlst);
	ft_dlstprint(dlst);

	ft_dlstadd_front(dlst, ft_dlstnew(10));
	ft_dlstadd_front(dlst, ft_dlstnew(20));
	ft_dlstadd_front(dlst, ft_dlstnew(30));
	ft_dlstprint(dlst);

	ft_printf("head is %p\n", *dlst);
	ft_printf("tail is %p\n\n", ft_dlstlast(*dlst));

	temp = ft_pop(dlst);
	// free(temp);
	// temp = NULL;
	ft_dlstadd_back(dlst, temp);
	ft_dlstprint(dlst);

	ft_printf("head is %p\n", *dlst);
	ft_printf("tail is %p\n\n", ft_dlstlast(*dlst));

	ft_dlstprint(dlst);
	ft_dlstclear(dlst);
	ft_dlstprint(dlst);
	return ;
}

static t_dlst	**ft_strtodlst(t_dlst *dlst[], char *argv[])
{
	int		i;
	int		len;
	char	tmp[1];
	// char	str[500];
	char	*str;
	char	**arr;

	i = 0;
	ft_strlcpy(tmp, " ", 2);
	// ft_strlcpy(str, "", 1);
	ft_printf("str to arr\n");
	while (argv[++i] != NULL)
	{
		// ft_strlcat(str, argv[i], ft_strlen(str) + ft_strlen(argv[i]) + 1);
		// ft_strlcat(str, tmp, ft_strlen(str) + ft_strlen(tmp) + 1);
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, tmp);
	}
	len = ft_split_size(str, ' ');
	arr = ft_split(str, ' ');
	free(str);

	i = 0;
	while (i < len)
	{
		ft_printf("%s", arr[i++]);
	}

	i = 0;
	ft_printf("arr to dlst\n");
	while (i < len)
	{
		// validate_input
		// ft_str_isdigit()
		// ft_str_isinteger()
		// ft_str_isduplicate()
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
	int		len;
	char	**arr;
	t_dlst	**stack;

	// test_dlst();
	// test_stack();
	*stack = NULL;
	stack = ft_strtodlst(stack, argv);

	ft_dlstclear(stack);
	ft_dlstprint(stack);

	return (0);
}
