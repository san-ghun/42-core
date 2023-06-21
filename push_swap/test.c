#include "push_swap.h"

static t_dlst	**init_dlst(t_dlst *dlst[])
{
	ft_dlstadd_back(dlst, ft_dlstnew(1));
	ft_dlstadd_back(dlst, ft_dlstnew(2));
	ft_dlstadd_back(dlst, ft_dlstnew(3));
	ft_dlstadd_back(dlst, ft_dlstnew(4));
	return (dlst);
}

int	main(void)
{
	t_dlst	**dlst;

	*dlst = NULL;
	// *dlst = ft_dlstnew(100);

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
	return (0);
}
