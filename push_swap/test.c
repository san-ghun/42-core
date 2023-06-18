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

	// *dlst = NULL;
	*dlst = ft_dlstnew(0);
	// dlst->next = ft_dlstnew(1);

	dlst = init_dlst(dlst);
	ft_dlstprint(dlst);

	ft_dlstadd_front(dlst, ft_dlstnew(10));
	ft_dlstadd_front(dlst, ft_dlstnew(20));
	ft_dlstprint(dlst);

	ft_dlstdelone(ft_dlstget(dlst, 1));
	ft_dlstdelone(ft_dlstget(dlst, 3));
	ft_dlstprint(dlst);

	ft_dlstdelone(ft_dlstget(dlst, 10));
	ft_dlstprint(dlst);

	ft_printf("%p\n", ft_dlstget(dlst, 20));
	ft_dlstdelone(ft_dlstget(dlst, 0));
	ft_dlstprint(dlst);
	ft_dlstclear(dlst);
	ft_dlstprint(dlst);
	return (0);
}
