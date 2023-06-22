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

static char	**ft_strtoarr(int argc, char *argv[])
{
	int		i;
	int		len;
	char	*tmp;
	char	*str;
	char	**arr;

	i = 0;
	// tmp = 
	// while (++i < argc)
	// {
	// 	ft_strlcat(str, argv[i], ft_strlen(argv[i]));
	// 	ft_strlcat(str, *tmp, sizeof(char));
	// }
	ft_printf("%s\n", str);
	len = ft_split_size(str, ' ');
	arr = ft_split(str, ' ');
	while (i < len)
	{
		ft_printf("%s ", arr[i++]);
		// validate_input
		// ft_str_isdigit()
		// ft_str_isinteger()
		// ft_str_isduplicate()
	}
	i = 0;
	while (i < len)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static t_dlst	**ft_arrtodlst(char **arr)
{
	int		i;
	t_dlst	**dlst;

	i = 0;
	return (NULL);
}

int	main(int argc, char *argv[])
{
	// char	**arr;
	// t_dlst	**stack;
	// test_dlst();
	test_stack();
	// arr = ft_strtoarr(argc, argv);
	return (0);
}
