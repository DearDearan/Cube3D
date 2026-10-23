/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 17:50:30 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/21 10:07:28 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define SIZE 10
#define CELLS 25

static void	set_tile_color(t_ctx *ctx, t_vec2i first, int *i)
{
	char		tile;
	int			x;
	int			y;
	mlx_color	color;

	x = first.x + i[0];
	y = first.y + i[1];
	tile = get_tile(ctx->map, x, y);
	color.rgba = 0x202020FF;
	if (tile == '1')
		color.rgba = 0xFFFFFFFF;
	else if (tile == '0' || tile == 'N' || tile == 'S' || tile == 'W'
		|| tile == 'E')
		color.rgba = 0x202020FF;
	else if (tile == 'B')
		color.rgba = 0xFF0000FF;
	else if (tile == '2'
		&& !ctx->doors[get_door(x, y, ctx->doors, ctx->d_count)].open)
		color.rgba = 0x0000FFFF;
	mlx_set_image_rectangle(ctx->render->mlx, ctx->map->mini,
		i[0] * SIZE, i[1] * SIZE, SIZE, SIZE, color);
}

static int	clamp(double pos, int len)
{
	int	start;

	start = (int)pos - CELLS / 2;
	if (start > len - CELLS)
		start = len - CELLS;
	if (start < 0)
		start = 0;
	return (start);
}

static void	calc_tiles(t_vec2i *first, t_ctx *ctx)
{
	first->x = clamp(ctx->player.x, (int)ctx->map->w);
	first->y = clamp(ctx->player.y, (int)ctx->map->h);
}

static void	draw_player(t_ctx *ctx, t_vec2i first)
{
	const mlx_color	color = {.rgba = 0x00FF00FF};
	int				x;
	int				y;

	x = (ctx->player.x - first.x) * SIZE - SIZE / 4;
	y = (ctx->player.y - first.y) * SIZE - SIZE / 4;
	mlx_set_image_rectangle(ctx->render->mlx, ctx->map->mini,
		x, y, SIZE / 2, SIZE / 2, color);
}

void	draw_tiles(t_ctx *ctx)
{
	int			i[2];
	t_vec2i		first;

	calc_tiles(&first, ctx);
	mlx_clear_image(ctx->render->mlx, ctx->map->mini,
		(mlx_color){.rgba = 0x000000FF});
	i[0] = 0;
	while (i[0] < CELLS)
	{
		i[1] = 0;
		while (i[1] < CELLS)
		{
			set_tile_color(ctx, first, i);
			i[1]++;
		}
		i[0]++;
	}
	draw_player(ctx, first);
	mlx_put_image_to_window(ctx->render->mlx, ctx->render->win,
		ctx->map->mini, 0, 0);
}
