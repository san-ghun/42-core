/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:48:23 by sanghupa          #+#    #+#             */
/*   Updated: 2023/05/19 13:03:12 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "MLX42/MLX42.h"
# include "libft.h"
# include "ft_printf.h"

# include <stdio.h>
# include <ctype.h>

#define WIDTH 512
#define HEIGHT 512

/* fractol_val_input.c */

/* fractol_error.c */

int	ft_str_isdigit(char *str);

int	ft_error_argv(void);

int	ft_error_argc(void);

/* fractol.c */

#endif