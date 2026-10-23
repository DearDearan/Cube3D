/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 03:12:23 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/23 10:06:02 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy_doors(t_ctx *ctx)
{
	if (ctx->txtrs && ctx->txtrs->door.img)
		mlx_destroy_image(ctx->render->mlx, ctx->txtrs->door.img);
	if (ctx->txtrs && ctx->txtrs->door.txtr)
		free(ctx->txtrs->door.txtr);
}

static void	free_imgs(t_ctx *ctx)
{
	if (ctx->txtrs && ctx->txtrs->no.img)
		mlx_destroy_image(ctx->render->mlx, ctx->txtrs->no.img);
	if (ctx->txtrs && ctx->txtrs->so.img)
		mlx_destroy_image(ctx->render->mlx, ctx->txtrs->so.img);
	if (ctx->txtrs && ctx->txtrs->ea.img)
		mlx_destroy_image(ctx->render->mlx, ctx->txtrs->ea.img);
	if (ctx->txtrs && ctx->txtrs->we.img)
		mlx_destroy_image(ctx->render->mlx, ctx->txtrs->we.img);
	if (ctx->sprite && ctx->sprite->sprite.img)
		mlx_destroy_image(ctx->render->mlx, ctx->sprite->sprite.img);
	if (ctx->render->img)
		mlx_destroy_image(ctx->render->mlx, ctx->render->img);
	if (ctx->txtrs && ctx->txtrs->no.txtr)
		free(ctx->txtrs->no.txtr);
	if (ctx->txtrs && ctx->txtrs->so.txtr)
		free(ctx->txtrs->so.txtr);
	if (ctx->txtrs && ctx->txtrs->ea.txtr)
		free(ctx->txtrs->ea.txtr);
	if (ctx->txtrs && ctx->txtrs->we.txtr)
		free(ctx->txtrs->we.txtr);
	if (ctx->sprite && ctx->sprite->sprite.txtr)
		free(ctx->sprite->sprite.txtr);
	if (ctx->map && ctx->map->mini)
		mlx_destroy_image(ctx->render->mlx, ctx->map->mini);
	destroy_doors(ctx);
}

static void	free_sounds(t_ctx *ctx)
{
	int	i;

	i = 0;
	if (ctx->snds.ch_music)
		mlx_destroy_audio_channel(ctx->render->mlx, ctx->snds.ch_music);
	if (ctx->snds.ch_sfx && ctx->snds.ch_sfx[0])
		mlx_destroy_audio_channel(ctx->render->mlx, ctx->snds.ch_sfx[0]);
	if (ctx->snds.ch_sfx && ctx->snds.ch_sfx[1])
		mlx_destroy_audio_channel(ctx->render->mlx, ctx->snds.ch_sfx[1]);
	if (ctx->snds.snd_msc)
		mlx_destroy_sound(ctx->render->mlx, ctx->snds.snd_msc);
	while (i < N_SFX && ctx->snds.snd_sfx)
	{
		if (ctx->snds.snd_sfx[i])
			mlx_destroy_sound(ctx->render->mlx, ctx->snds.snd_sfx[i]);
		i++;
	}
	free(ctx->snds.ch_sfx);
	free(ctx->snds.snd_sfx);
}

void	destroy_mlx(t_ctx *context)
{
	if (context->render->mlx)
	{
		free_imgs(context);
		free_sounds(context);
	}
	if (context->doors)
		free(context->doors);
	if (context->render->win)
		mlx_destroy_window(context->render->mlx, context->render->win);
	if (context->render->mlx)
		mlx_destroy_context(context->render->mlx);
	if (context->render)
		free(context->render);
	if (context->txtrs)
		free(context->txtrs);
	if (context->sprite)
		free(context->sprite);
	if (context->map)
		free(context->map->map);
	free(context->map);
}
