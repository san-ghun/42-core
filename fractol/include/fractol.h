/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:48:23 by sanghupa          #+#    #+#             */
/*   Updated: 2023/05/12 12:13:39 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

# include <stdio.h>
# include <ctype.h>

/* fractol_val_input.c */
/* fractol_rules.c */
/* fractol_sort.c */

/* fractol_error.c */

int	ft_str_isdigit(char *str);

int	ft_error_argv(void);

int	ft_error_argc(void);

/* fractol.c */

#endif