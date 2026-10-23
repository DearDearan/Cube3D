/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:44:47 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/20 10:51:00 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTING_H
# define CASTING_H

typedef struct s_castdata	t_cast;
typedef struct s_context	t_ctx;
typedef struct s_draw		t_draw;
typedef struct s_images		t_img;
typedef struct s_intvec		t_vec2i;
typedef struct s_floatvec	t_vec2;
typedef struct s_sprite		t_sprt;

/* INIT_CAST_C */

void		init_cast(t_cast *cast, t_ctx *ctx, int screen_x);
void		calc_dist_and_step(t_cast *cast);
void		calc_map_and_deltas(t_cast *cast);

/* RAYCAST_C */

void		raycast(t_ctx *con, t_cast *cast, int screen_x);
void		render(t_ctx *ctx, t_draw *rend);
void		calc_wall_dst(t_cast *cst);
void		calc_wall_x(t_cast *cst);

/* GET_TXTRS_C */
mlx_color	get_txtr_pixel(t_ctx *ctx, t_cast *cst, t_img *txtr);
int			get_txtr_width(t_ctx *ctx, t_cast *cst);
int			get_txtr_height(t_ctx *ctx, t_cast *cst);
t_img		get_txtr_image(t_ctx *ctx, t_cast *cst);

/* SPRITES_C */
void		draw_sprt_col(mlx_color *color, t_sprt *sprt, t_vec2i tex);
void		calc_sprite(t_sprt *sprt, t_ctx *ctx);
void		draw_sprt(mlx_color *color, t_sprt *sprt, double *wall_dst_col,
				int screen_x);
mlx_color	color_blend_quick(mlx_color bg, mlx_color fg);
mlx_color	color_blend(mlx_color bg, mlx_color fg);

/* CALC_DOOR_C */
bool		handle_doors(t_ctx *ctx, t_cast *cst);
int			get_door_txtr_x(t_ctx *ctx, t_cast *cst);

/* MINIMAP_C */
void		draw_tiles(t_ctx *ctx);

#endif
