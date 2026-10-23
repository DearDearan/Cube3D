/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:09:49 by lifranco          #+#    #+#             */
/*   Updated: 2026/09/10 00:37:48 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_draw(t_vec2i *lim, double *ratio, int txtr_h, t_cast *cst)
{
	int	h;

	h = 1.0 / cst->wall_dst * HEIGHT;
	lim->x = (HEIGHT - h) / 2.0;
	lim->y = HEIGHT - lim->x;
	*ratio = (double)txtr_h / h;
}

static void	fill_colors(mlx_color *color, t_ctx *ctx, t_cast *cst)
{
	const int	txtr_h = get_txtr_height(ctx, cst);
	const t_img	curr = get_txtr_image(ctx, cst);
	int			i;
	t_vec2i		lim;
	double		utils[2];

	i = 0;
	utils[1] = 0;
	cst->txtrs.x = (int)(cst->wall_x * get_txtr_width(ctx, cst));
	calc_draw(&lim, &utils[0], txtr_h, cst);
	if (lim.x < 0)
		utils[1] = -lim.x * utils[0];
	if (lim.y > HEIGHT)
		lim.y = HEIGHT;
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
	int			screen_x;
	t_cast		cst;
	mlx_color	color[HEIGHT];

	screen_x = 0;
	while (screen_x < WIDTH)
	{
		raycast(ctx, &cst, screen_x);
		fill_colors(color, ctx, &cst);
		rend->color = color;
		draw(rend, screen_x);
		screen_x++;
	}
	mlx_put_transformed_image_to_window(rend->mlx, rend->win,
		rend->img, 0, 0, 1, 1, 0);
}
