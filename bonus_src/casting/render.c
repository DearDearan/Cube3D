/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:09:49 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/15 15:57:59 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	calc_draw(t_vec2i *lim, double *u, t_cast *cst, t_ctx *ctx)
{
	double		h;

	*u = 0;
	h = 1.0 / cst->wall_dst * HEIGHT;
	lim->x = ctx->center_h - h / 2;
	lim->y = ctx->center_h + h / 2;
	return ((get_txtr_height(ctx, cst) / h));
}

static void	check_lims(t_vec2i *lim, double *utils)
{
	if (lim->x < 0)
		utils[1] = -lim->x * utils[0];
	if (lim->x > HEIGHT)
		lim->x = HEIGHT;
	if (lim->y > HEIGHT)
		lim->y = HEIGHT;
}

static void	fill_colors(mlx_color *color, t_ctx *ctx, t_cast *cst)
{
	const t_img	curr = get_txtr_image(ctx, cst);
	int			i;
	t_vec2i		lim;
	double		utils[2];

	i = 0;
	if (!cst->is_door)
		cst->txtrs.x = (int)(cst->wall_x * get_txtr_width(ctx, cst));
	else
		cst->txtrs.x = get_door_txtr_x(ctx, cst);
	utils[0] = calc_draw(&lim, &utils[1], cst, ctx);
	check_lims(&lim, utils);
	while (i < lim.x)
		color[i++] = ctx->txtrs->ceiling;
	while (i < lim.y)
	{
		cst->txtrs.y = (int)utils[1];
		color[i++] = curr.txtr[cst->txtrs.x * curr.h + cst->txtrs.y];
		utils[1] += utils[0];
	}
	while (i < HEIGHT)
		color[i++] = ctx->txtrs->floor;
}

static void	draw(t_draw *rend, int screen_x)
{
	mlx_set_image_region(rend->mlx, rend->img, screen_x,
		0, 1, HEIGHT, rend->color);
}

void	render(t_ctx *ctx, t_draw *rend)
{
	t_cast		cst;
	mlx_color	color[HEIGHT];
	double		wall_dst_col[WIDTH];
	int			screen_x;

	cst.interact = false;
	screen_x = 0;
	calc_sprite(ctx->sprite, ctx);
	while (screen_x < WIDTH)
	{
		raycast(ctx, &cst, screen_x);
		wall_dst_col[screen_x] = cst.wall_dst;
		fill_colors(color, ctx, &cst);
		draw_sprt(color, ctx->sprite, wall_dst_col, screen_x);
		rend->color = color;
		draw(rend, screen_x);
		screen_x++;
	}
	rend->color = NULL;
	mlx_put_transformed_image_to_window(rend->mlx, rend->win,
		rend->img, 0, 0, 1, 1, 0);
	if (ctx->mini_op)
		draw_tiles(ctx);
}
