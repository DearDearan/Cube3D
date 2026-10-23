/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 03:02:05 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/20 10:48:20 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	change_door_state(t_ctx *new, t_cast *cst)
{
	int	i;

	i = get_door(cst->map.x, cst->map.y,
			new->doors, new->d_count);
	if (cst->wall_dst > 1.0 || i == -1)
		return ;
	new->doors[i].open = !new->doors[i].open;
	if (new->doors[i].open)
		mlx_play_sound(new->render->mlx, new->snds.ch_sfx[1],
			new->snds.snd_sfx[0]);
	else
		mlx_play_sound(new->render->mlx, new->snds.ch_sfx[1],
			new->snds.snd_sfx[1]);
}

static void	unfocus(t_ctx *ctx)
{
	ctx->focus = !ctx->focus;
	if (!ctx->focus)
		mlx_mouse_show(ctx->render->mlx);
	else
	{
		mlx_mouse_hide(ctx->render->mlx);
		mlx_mouse_move(ctx->render->mlx,
			ctx->render->win, WIDTH / 2, HEIGHT / 2);
	}
}

void	key_down_hook(int key, void *param)
{
	t_ctx	*new;
	t_cast	cst;

	new = (t_ctx *)param;
	cst.interact = true;
	if (key == MLX_KEY_ESCAPE)
		mlx_loop_end(new->render->mlx);
	else if (key == MLX_KEY_W)
		new->held.w_held = true;
	else if (key == MLX_KEY_S)
		new->held.s_held = true;
	else if (key == MLX_KEY_D)
		new->held.d_held = true;
	else if (key == MLX_KEY_A)
		new->held.a_held = true;
	else if (key == MLX_KEY_E)
	{
		raycast(new, &cst, WIDTH / 2);
		change_door_state(new, &cst);
	}
	else if (key == MLX_KEY_TAB)
		new->mini_op = !new->mini_op;
	else if (key == MLX_KEY_F11)
		unfocus(new);
}

void	key_up_hook(int key, void *param)
{
	t_ctx	*new;

	new = (t_ctx *)param;
	if (key == MLX_KEY_W)
		new->held.w_held = false;
	else if (key == MLX_KEY_S)
		new->held.s_held = false;
	else if (key == MLX_KEY_D)
		new->held.d_held = false;
	else if (key == MLX_KEY_A)
		new->held.a_held = false;
}

void	key_held(t_ctx *ctx)
{
	if (ctx->focus)
	{
		move_player(ctx);
		if ((fabs(ctx->vel.x) > 1e-3 || fabs(ctx->vel.y) > 1e-3)
			&& ((ctx->frame % 50) == 0))
		{
			mlx_set_channel_speed(ctx->render->mlx, ctx->snds.ch_sfx[0],
				drand48() * 0.3 + 0.6);
			mlx_play_sound(ctx->render->mlx, ctx->snds.ch_sfx[0],
				ctx->snds.snd_sfx[2]);
		}
		rotate_mouse(ctx);
	}
}
