/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:23:17 by sanghupa          #+#    #+#             */
/*   Updated: 2023/12/10 21:30:47 by sanghupa         ###   ########.fr       */
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

/// minilibx
# include "mlx.h"

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
** -----------------------------------------------------------------------------
** Result Macros
** -----------------------------------------------------------------------------
*/

# define TRUE 			1
# define FALSE 			0
# define VALID			0
# define INVALID		1
# define CHECK			1
# define PARSE			0
# define SUCCESS		1
# define END			0
# define ERROR 			-1

/*
** =============================================================================
** Type Definition
** =============================================================================
*/

typedef int				t_bool;
typedef pthread_mutex_t	t_mux;

typedef struct s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct s_ray
{
	t_vec3		origin;
	t_vec3		direction;
}				t_ray;

typedef struct s_square {
	int			x;
	int			y;
	int			size;
	int			color;
}				t_square;

typedef struct s_temp {
	int		size;
	int		color;
}				t_temp;

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
t_vec3	init_vector(double x, double y, double z);

/// color.c
int		get_trgb(int opacity, int red, int green, int blue);
int		get_opacity(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

/// hook_key.c
int		key_hooks(int keycode, t_data *img);
int		close_mlx(t_data *img);

/// hook_mouse.c
int		mouse_hooks(int button, int m_x, int m_y, t_data *img);

/// mlx_util.c
void	put_pixel_data(t_data *data, int x, int y, int color);
void	draw_square(t_square square, t_data *img);
t_temp	*single_temp(void);

/// vector operations

/// @brief addition of two vectors
/// @param u vector
/// @param v vector
/// @return a vector
t_vec3	add(t_vec3 u, t_vec3 v);

/// @brief subtraction of two vectors
/// @param u vector
/// @param v vector
/// @return a vector
t_vec3	subtract(t_vec3 u, t_vec3 v);

/// @brief scale (scalar multiplication) of a vector
/// @param v vector
/// @param s scalar
/// @return a vector
t_vec3	scale(t_vec3 v, double s);

/// @brief dot (inner) product of two vectors
/// @param u vector
/// @param v vector
/// @return (double) a scalar
double	dot(t_vec3 u, t_vec3 v);

/// @brief cross product of two vectors
/// @param u vector
/// @param v vector
/// @return a vector
t_vec3	cross(t_vec3 u, t_vec3 v);

t_vec3	flip(t_vec3 v);
double	len_pow(t_vec3 v);
double	len_sqrt(t_vec3 v);
t_vec3	unit(t_vec3 v);
t_bool	near_zero(t_vec3 v);

#endif
