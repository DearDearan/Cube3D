/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 03:02:05 by lifranco          #+#    #+#             */
/*   Updated: 2026/09/27 21:45:54 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_down_hook(int key, void *param)
{
	t_ctx	*new;

	new = (t_ctx *)param;
	if (key == MLX_KEY_ESCAPE)
		mlx_loop_end(new->render->mlx);
	if (key == MLX_KEY_W)
		new->held.w_held = true;
	if (key == MLX_KEY_S)
		new->held.s_held = true;
	if (key == MLX_KEY_D)
		new->held.d_held = true;
	if (key == MLX_KEY_A)
		new->held.a_held = true;
}

void	key_up_hook(int key, void *param)
{
	t_ctx	*new;

	new = (t_ctx *)param;
	if (key == MLX_KEY_W)
		new->held.w_held = false;
	if (key == MLX_KEY_S)
		new->held.s_held = false;
	if (key == MLX_KEY_D)
		new->held.d_held = false;
	if (key == MLX_KEY_A)
		new->held.a_held = false;
}

static void	move_player(t_ctx *ctx)
{
	if (ctx->held.w_held)
	{
		ctx->player.x += ctx->dir.x * (MOV_SPEED / 10);
		ctx->player.y += ctx->dir.y * (MOV_SPEED / 10);
	}
	if (ctx->held.s_held)
	{
		ctx->player.x -= ctx->dir.x * (MOV_SPEED / 10);
		ctx->player.y -= ctx->dir.y * (MOV_SPEED / 10);
	}
}

static void	rotate_player(t_ctx *ctx)
{
	double	old_dir;
	t_vec2	old_p;
	double	rot;

	rot = ROT_SPEED / 10;
	old_dir = ctx->dir.x;
	old_p = ctx->plane;
	if (ctx->held.d_held && !ctx->held.a_held)
	{
		ctx->dir.x = ctx->dir.x * cos(rot) - ctx->dir.y * sin(rot);
		ctx->dir.y = old_dir * sin(rot) + ctx->dir.y * cos(rot);
		ctx->plane.x = ctx->plane.x * cos(rot) - old_p.y * sin(rot);
		ctx->plane.y = old_p.x * sin(rot) + ctx->plane.y * cos(rot);
	}
	if (ctx->held.a_held && !ctx->held.d_held)
	{
		ctx->dir.x = ctx->dir.x * cos(-rot) - ctx->dir.y * sin(-rot);
		ctx->dir.y = old_dir * sin(-rot) + ctx->dir.y * cos(-rot);
		ctx->plane.x = ctx->plane.x * cos(-rot) - old_p.y * sin(-rot);
		ctx->plane.y = old_p.x * sin(-rot) + ctx->plane.y * cos(-rot);
	}
}

void	key_held(t_ctx *ctx)
{
	move_player(ctx);
	rotate_player(ctx);
}
