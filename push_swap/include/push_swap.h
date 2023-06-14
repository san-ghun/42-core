/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:48:59 by sanghupa          #+#    #+#             */
/*   Updated: 2023/06/14 17:50:22 by sanghupa         ###   ########.fr       */
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

typedef struct s_dbl_list
{
	void				*content;
	struct s_dbl_list	*prev;
	struct s_dbl_list	*next;
}				t_dbl_list;

/* push_swap_error.c */

int	ft_error(void);

int	ft_str_isdigit(char *str);

int	ft_iserror(char **arg);

/* push_swap_val_input.c */

/* push_swap_rules.c */

/* push_swap_sort.c */

/* push_swap.c */

#endif