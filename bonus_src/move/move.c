/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 04:48:53 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/20 10:41:44 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_colliding(t_ctx *ctx, t_door *d, t_map *map, t_vec2 target)
{
	int	i[4];

	i[0] = get_door(target.x - HITSIZE, target.y - HITSIZE, d, ctx->d_count);
	i[1] = get_door(target.x - HITSIZE, target.y + HITSIZE, d, ctx->d_count);
	i[2] = get_door(target.x + HITSIZE, target.y - HITSIZE, d, ctx->d_count);
	i[3] = get_door(target.x + HITSIZE, target.y + HITSIZE, d, ctx->d_count);
	return (
		get_tile(map, target.x - HITSIZE, target.y - HITSIZE) == '1'
		|| get_tile(map, target.x - HITSIZE, target.y + HITSIZE) == '1'
		|| get_tile(map, target.x + HITSIZE, target.y - HITSIZE) == '1'
		|| get_tile(map, target.x + HITSIZE, target.y + HITSIZE) == '1'
		|| (get_tile(map, target.x - HITSIZE, target.y - HITSIZE) == '2'
			&& i[0] != -1 && d[i[0]].open == false)
		|| (get_tile(map, target.x - HITSIZE, target.y + HITSIZE) == '2'
			&& i[1] != -1 && d[i[1]].open == false)
		|| (get_tile(map, target.x + HITSIZE, target.y - HITSIZE) == '2'
			&& i[2] != -1 && d[i[2]].open == false)
		|| (get_tile(map, target.x + HITSIZE, target.y + HITSIZE) == '2'
			&& i[3] != -1 && d[i[3]].open == false));
}

static void	player_collisions(t_ctx *ctx)
{
	t_vec2	target;

	target.x = ctx->player.x + ctx->vel.x;
	target.y = ctx->player.y + ctx->vel.y;
	if (is_colliding(ctx, ctx->doors, ctx->map, vec2(target.x, ctx->player.y)))
	{
		if (ctx->vel.x > 0)
			target.x = ceil(ctx->player.x) - HITSIZE - 1e-6;
		else
			target.x = floor(ctx->player.x) + HITSIZE + 1e-6;
		ctx->vel.x /= 2;
	}
	if (is_colliding(ctx, ctx->doors, ctx->map, vec2(ctx->player.x, target.y))
		|| (target.x == ctx->player.x + ctx->vel.x
			&& is_colliding(ctx, ctx->doors, ctx->map, target)))
	{
		if (ctx->vel.y > 0)
			target.y = ceil(ctx->player.y) - HITSIZE - 1e-6;
		else
			target.y = floor(ctx->player.y) + HITSIZE + 1e-6;
		ctx->vel.y /= 2;
	}
	ctx->player = target;
}

void	move_player(t_ctx *ctx)
{
	ctx->vel.x *= FRICTION;
	ctx->vel.y *= FRICTION;
	if (ctx->held.w_held)
	{
		ctx->vel.x += ctx->dir.x * MOV_S;
		ctx->vel.y += ctx->dir.y * MOV_S;
	}
	if (ctx->held.s_held)
	{
		ctx->vel.x -= ctx->dir.x * MOV_S;
		ctx->vel.y -= ctx->dir.y * MOV_S;
	}
	if (ctx->held.a_held)
	{
		ctx->vel.x += ctx->dir.y * MOV_S;
		ctx->vel.y -= ctx->dir.x * MOV_S;
	}
	if (ctx->held.d_held)
	{
		ctx->vel.x -= ctx->dir.y * MOV_S;
		ctx->vel.y += ctx->dir.x * MOV_S;
	}
	player_collisions(ctx);
}

static void	rotate_player(t_ctx *ctx, double rot)
{
	double	old_dir;
	t_vec2	old_p;

	old_dir = ctx->dir.x;
	old_p = ctx->plane;
	ctx->dir.x = ctx->dir.x * cos(rot) - ctx->dir.y * sin(rot);
	ctx->dir.y = old_dir * sin(rot) + ctx->dir.y * cos(rot);
	ctx->plane.x = ctx->plane.x * cos(rot) - old_p.y * sin(rot);
	ctx->plane.y = old_p.x * sin(rot) + ctx->plane.y * cos(rot);
}

void	rotate_mouse(t_ctx *ctx)
{
	double	rot;

	mlx_mouse_get_pos(ctx->render->mlx, &ctx->held.mouse.x,
		&ctx->held.mouse.y);
	rot = ((WIDTH / 2)) - ctx->held.mouse.x;
	ctx->center_h += ((HEIGHT / 2)) - ctx->held.mouse.y;
	if (ctx->center_h > HEIGHT * 1.5)
		ctx->center_h = HEIGHT * 1.5;
	if (ctx->center_h < -HEIGHT * 0.5)
		ctx->center_h = -HEIGHT * 0.5;
	rotate_player(ctx, rot / -1000);
}
