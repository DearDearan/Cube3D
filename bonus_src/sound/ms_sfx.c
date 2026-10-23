/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_sfx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 04:11:52 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/20 10:19:13 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	fill_ms_sfx(t_ctx *ctx, char **paths)
{
	int	i;

	i = 0;
	ctx->snds.snd_sfx = malloc(3 * sizeof(mlx_sound));
	ctx->snds.ch_music = mlx_new_audio_channel(ctx->render->mlx);
	ctx->snds.ch_sfx = malloc(2 * sizeof(mlx_channel));
	ctx->snds.ch_sfx[0] = mlx_new_audio_channel(ctx->render->mlx);
	ctx->snds.ch_sfx[1] = mlx_new_audio_channel(ctx->render->mlx);
	if (!ctx->snds.ch_music || !ctx->snds.ch_sfx || !*ctx->snds.ch_sfx)
		return (false);
	ctx->snds.snd_msc = mlx_new_sound_from_wav(ctx->render->mlx,
			paths[0], NULL);
	ctx->snds.snd_sfx[0] = mlx_new_sound_from_wav(ctx->render->mlx,
			paths[1], NULL);
	ctx->snds.snd_sfx[1] = mlx_new_sound_from_wav(ctx->render->mlx,
			paths[2], NULL);
	ctx->snds.snd_sfx[2] = mlx_new_sound_from_wav(ctx->render->mlx,
			paths[3], NULL);
	while (i < N_SFX)
	{
		if (!ctx->snds.snd_msc || !ctx->snds.snd_sfx[i])
			return (false);
		i++;
	}
	return (true);
}
