/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:48:59 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/15 23:44:14 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

# include <stdio.h>
# include <ctype.h>

// Limit Loop: use addition to while condition
# define MAX_ITER	500

// Prevent Heap mem leak: use addition to char or array
# define DATA_SIZE	500

typedef struct s_dlst
{
	void				*content;
	struct s_dlst		*prev;
	struct s_dlst		*next;
}				t_dlst;

/* push_swap_dlst_create.c */

t_dlst	*ft_dlstnew(void *content);

t_dlst	**init_dlst(void);

void	ft_dlstadd_front(t_dlst *dlst[], t_dlst *new);

void	ft_dlstadd_back(t_dlst *dlst[], t_dlst *new);

/* push_swap_dlst_read.c */

t_dlst	*ft_dlstget(t_dlst *dlst[], void *content);

/* push_swap_dlst_update.c */

void	ft_dlstupdate(t_dlst *dlst[], void *old, void *new);

/* push_swap_dlst_delete.c */

void	ft_dlstdelone(t_dlst *dlst);

/* push_swap_dlst_util.c */

int		ft_dlstsize(t_dlst *dlst);

t_dlst	*ft_dlstlast(t_dlst *dlst[]);

/* push_swap_error.c */

int		ft_error(void);

int		ft_str_isdigit(char *str);

int		ft_iserror(char **arg);

/* push_swap_val_input.c */

/* push_swap_rules.c */

/* push_swap_sort.c */

/* push_swap.c */

#endif
