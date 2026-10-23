/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:07:33 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/12 14:24:58 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdint.h>
# include "MacroLibX/includes/mlx_extended.h"
# include "game.h"
# include "parsing.h"
# include "casting.h"
# include "libft/includes/libft.h"
# include "peggle_deluxe/include/peggle_deluxe.h"
# include "vectors.h"
# include "keys.h"
# include "MacroLibX/includes/mlx_keycodes.h"
# define WIDTH 1920
# define HEIGHT 1080
# define MOV_SPEED 1.0f
# define ROT_SPEED 0.4f
# undef WE

typedef enum e_side
{
	NO,
	SO,
	EA,
	WE,
	NONE
}				t_side;

typedef struct s_draw
{
	double		big;
	mlx_context	mlx;
	mlx_window	win;
	mlx_image	img;
	mlx_color	*color;
}	t_draw;

typedef struct s_key
{
	bool	w_held;
	bool	s_held;
	bool	d_held;
	bool	a_held;
}				t_key;

typedef struct s_map
{
	char	*map;
	size_t	h;
	size_t	w;
	bool	error;
}				t_map;

typedef struct s_images
{
	mlx_image		img;
	mlx_color		*txtr;
	int				w;
	int				h;
}				t_img;

typedef struct s_textures
{
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;
	mlx_color	floor;
	mlx_color	ceiling;
}				t_txtr;

typedef struct s_context
{
	t_vec2	player;
	t_vec2	plane;
	t_vec2	dir;

	t_map	*map;
	t_draw	*render;
	t_key	held;
	t_txtr	*txtrs;
}				t_ctx;

typedef struct s_castdata
{
	size_t	in_render;
	bool	render;
	t_vec2	delta;
	t_vec2i	map;
	t_vec2	side_dist;
	t_vec2	origin;
	t_vec2	dir;
	t_vec2i	step;
	double	wall_dst;
	bool	side;
	double	wall_x;
	t_vec2i	txtrs;
	t_side	touched;
}				t_cast;

t_ctx	parse(char *map);
int		calc_tile(t_map *map, uintmax_t x, uintmax_t y);
char	get_tile(t_map *map, uintmax_t x, uintmax_t y);
void	set_tile(char tile, t_vec2i vec, t_map *map);
bool	parse_map(char *filename, t_ctx *res);
char	*cb_readall(int fd);
void	destroy_mlx(t_ctx *context);

#endif