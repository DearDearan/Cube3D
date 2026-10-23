/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 23:39:28 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/20 10:51:59 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_sprite(t_sprt *sprt, t_ctx *ctx)
{
	t_vec2	sprite_p;
	double	inv_det;

	sprite_p.x = sprt->pos.x - ctx->player.x;
	sprite_p.y = sprt->pos.y - ctx->player.y;
	inv_det = 1.0 / (ctx->plane.x * ctx->dir.y - ctx->dir.x * ctx->plane.y);
	sprt->trsfm.x = inv_det * (ctx->dir.y * sprite_p.x
			- ctx->dir.x * sprite_p.y);
	sprt->trsfm.y = inv_det * (-ctx->plane.y * sprite_p.x
			+ ctx->plane.x * sprite_p.y);
	sprt->sc_h = 1.0 / sprt->trsfm.y * HEIGHT;
	sprt->sc_w = ((double)sprt->sprite.w / sprt->sprite.h) * sprt->sc_h;
	sprt->cam_x = (sprt->trsfm.x / sprt->trsfm.y + 1) * (WIDTH / 2);
	sprt->start.x = -sprt->sc_w / 2 + sprt->cam_x;
	sprt->start.y = ctx->center_h - (sprt->sc_h * 0.5) / 2;
	sprt->end.x = sprt->sc_w / 2 + sprt->cam_x;
	sprt->end.y = ctx->center_h + (sprt->sc_h / 0.8) / 2;
	sprt->sc_s = sprt->start.y;
	if (sprt->sc_s < 0)
		sprt->sc_s = 0;
	sprt->sc_e = sprt->end.y;
	if (sprt->sc_e >= HEIGHT)
		sprt->sc_e = HEIGHT - 1;
}

void	draw_sprt(mlx_color *color, t_sprt *sprt, double *wall_dst_col,
		int screen_x)
{
	double	ratio;
	t_vec2i	tex;

	if ((screen_x < sprt->start.x || screen_x >= sprt->end.x)
		|| (sprt->trsfm.y >= wall_dst_col[screen_x]))
		return ;
	ratio = (double)(screen_x - sprt->start.x) / (sprt->end.x - sprt->start.x);
	tex.x = (int)(ratio * sprt->sprite.w);
	draw_sprt_col(color, sprt, tex);
}

void	draw_sprt_col(mlx_color *color, t_sprt *sprt, t_vec2i tex)
{
	int		i;
	double	ratio;
	double	v;

	ratio = 1.0 / (sprt->end.y - sprt->start.y);
	v = (sprt->sc_s - sprt->start.y) * ratio;
	i = sprt->sc_s;
	while (i < sprt->sc_e)
	{
		tex.y = (int)(v * sprt->sprite.h);
		color[i] = color_blend(color[i],
				sprt->sprite.txtr[tex.x * sprt->sprite.h + tex.y]);
		i++;
		v += ratio;
	}
}

mlx_color	color_blend_quick(mlx_color bg, mlx_color fg)
{
	const double	fga = fg.a / 255.0;
	const double	bga = bg.a / 255.0 * (1.0 - fga);
	const double	blend = fga + bga;

	return ((mlx_color){
		.r = (fg.r * fga + bg.r * bga) / blend,
		.g = (fg.g * fga + bg.g * bga) / blend,
		.b = (fg.b * fga + bg.b * bga) / blend,
		.a = blend * 255
	});
}

mlx_color	color_blend(mlx_color bg, mlx_color fg)
{
	if (fg.a == 0)
		return (bg);
	if (fg.a == 255 || bg.a == 0)
		return (fg);
	return (color_blend_quick(bg, fg));
}
