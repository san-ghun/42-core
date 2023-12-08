/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:23:17 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/08 17:45:29 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*
** =============================================================================
** Dependency
** =============================================================================
*/

/// open, close
# include <fcntl.h>

/// read, write
# include <unistd.h>

/// printf, perror
# include <stdio.h>

/// strerror
# include <string.h>

/// malloc, free, exit
# include <stdlib.h>

# include <math.h>
# include <stdint.h>
# include <pthread.h>

// =============================================================================

/// minilibx
# include "mlx.h"
// # include "mlx_int.h"

/// libft
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "from_ms.h"

/// extra
# include "key_linux.h"
// # include "key_macos.h"

/*
** =============================================================================
** Macro
** =============================================================================
*/

/*
** =============================================================================
** Structure
** =============================================================================
*/

typedef struct s_data {
	void	*img;
	char	*addr;
	int		h;
	int		w;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}				t_vars;

/*
** =============================================================================
** Prototype
** =============================================================================
*/

/// new.c
t_vars	*single_vars(void);
t_vars	*new_program(int w, int h, char *str);
t_data	*new_img(int w, int h, t_vars *vars);

/// color.c
int		get_trgb(int opacity, int red, int green, int blue);
int		get_opacity(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

/// hook.c
int		close_mlx(int keycode, t_vars *vars);

/// mlx_util.c
void	put_pixel_data(t_data *data, int x, int y, int color);

#endif
