/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                             ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀    */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:07:33 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/22 15:20:48 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟           */
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
# include <sys/time.h>
# include "mlx_extended.h"
# include "game.h"
# include "parsing.h"
# include "casting.h"
# include "libft.h"
# include "peggle_deluxe.h"
# include "vectors.h"
# include "keys.h"
# include "mlx_keycodes.h"
# define WIDTH 1920
# define HEIGHT 1080
# define MOV_S 0.008f
# define ROT_S 0.4f
# define HITSIZE 0.4f
# define FRICTION 0.85f
# define N_SFX 3
# define MINMAP 250
# undef WE

typedef enum e_side
{
	NO,
	SO,
	EA,
	WE,
	NONE
}	t_side;

typedef struct s_images
{
	mlx_image		img;
	mlx_color		*txtr;
	int				w;
	int				h;
}	t_img;

typedef struct s_doors
{
	double	progress;
	bool	open;
	t_vec2i	pos;
}	t_door;	

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
	t_vec2i	mouse;
}				t_key;

typedef struct s_map
{
	char		*map;
	size_t		h;
	size_t		w;
	mlx_image	mini;
}				t_map;

typedef struct s_sprite
{
	t_img	sprite;
	t_vec2	trsfm;
	t_vec2	pos;
	t_vec2i	start;
	t_vec2i	end;

	int		sc_s;
	int		sc_e;
	int		cam_x;
	double	sc_h;
	double	sc_w;
}				t_sprt;

typedef struct s_textures
{
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;
	mlx_color	floor;
	mlx_color	ceiling;
	t_img		door;

}	t_txtr;

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
	t_vec2i	txtrs;
	double	wall_dst;
	bool	side;
	double	wall_x;
	t_side	touched;
	bool	is_door;
	bool	interact;
}				t_cast;

typedef struct s_sounds
{
	mlx_channel	ch_music;
	mlx_channel	*ch_sfx;
	mlx_sound	snd_msc;
	mlx_sound	*snd_sfx;
	float		vol;
}				t_snd;

typedef struct s_context
{
	t_vec2	player;
	t_vec2	vel;
	t_vec2	plane;
	t_vec2	dir;
	t_map	*map;
	t_draw	*render;
	t_key	held;
	t_txtr	*txtrs;
	t_sprt	*sprite;
	t_door	*doors;
	t_snd	snds;
	int		center_h;
	int		d_count;
	int		frame;
	bool	focus;
	bool	mini_op;
}				t_ctx;

int		calc_tile(t_map *map, uintmax_t x, uintmax_t y);
char	get_tile(t_map *map, uintmax_t x, uintmax_t y);
void	set_tile(char tile, t_vec2i vec, t_map *map);

#endif
