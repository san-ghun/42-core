/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:23:17 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/08 19:42:59 by sanghupa         ###   ########.fr       */
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

/// Limit Loop: use addition to while condition (dev)
# define MAX_ITER	5000

/// Prevent Heap mem leak: use addition to char or array (dev)
# define DATA_SIZE	3072

# define INTMAX		2147483647
# define INTMIN		-2147483648

/*
** =============================================================================
** Structure
** =============================================================================
*/

typedef struct s_square {
	unsigned int	x;
	unsigned int	y;
	unsigned int	size;
	int				color;
}				t_square;

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

/// hook_key.c
int		key_hooks(int keycode, t_data *img);

/// hook_mouse.c
int		mouse_hooks(int button, int m_x, int m_y, t_data *img);

/// mlx_util.c
void	put_pixel_data(t_data *data, int x, int y, int color);
void	draw_square(t_square square, t_data *img);

#endif
