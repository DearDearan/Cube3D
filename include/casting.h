/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.h                                           ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀    */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:44:47 by lifranco          #+#    #+#             */
/*   Updated: 2026/09/29 06:07:46 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟           */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTING_H
# define CASTING_H

typedef struct s_castdata	t_cast;
typedef struct s_context	t_ctx;
typedef struct s_draw		t_draw;
typedef struct s_images		t_img;
/* INIT_CAST_C */

void		init_cast(t_cast *cast, t_ctx *ctx, int screen_x);
void		calc_dist_and_step(t_cast *cast);
void		calc_map_and_deltas(t_cast *cast);

/* RAYCAST_C */

void		raycast(t_ctx *con, t_cast *cast, int screen_x);
void		render(t_ctx *ctx, t_draw *rend);

/* GET_TXTRS_C */
mlx_color	get_txtr_pixel(t_ctx *ctx, t_cast *cst, t_img *txtr);
int			get_txtr_width(t_ctx *ctx, t_cast *cst);
int			get_txtr_height(t_ctx *ctx, t_cast *cst);
t_img		get_txtr_image(t_ctx *ctx, t_cast *cst);

#endif
