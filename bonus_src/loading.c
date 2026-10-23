/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 06:07:17 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/20 10:07:00 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_txtr(t_ctx *ctx, t_img	*txtr)
{
	long		i;
	long		j;
	long		total;
	mlx_color	*pixels;

	i = 0;
	total = 0;
	pixels = ft_calloc(txtr->w * txtr->h, sizeof(mlx_color));
	while (i < txtr->w)
	{
		j = 0;
		while (j < txtr->h)
		{
			pixels[total] = mlx_get_image_pixel(ctx->render->mlx,
					txtr->img, i, j);
			j++;
			total++;
		}
		i++;
	}
	txtr->txtr = pixels;
}

static bool	make_txtrs(t_ctx *ctx)
{
	fill_txtr(ctx, &ctx->txtrs->no);
	fill_txtr(ctx, &ctx->txtrs->so);
	fill_txtr(ctx, &ctx->txtrs->we);
	fill_txtr(ctx, &ctx->txtrs->ea);
	fill_txtr(ctx, &ctx->sprite->sprite);
	fill_txtr(ctx, &ctx->txtrs->door);
	if (!ctx->txtrs->no.txtr || !ctx->txtrs->so.txtr || !ctx->txtrs->we.txtr
		|| !ctx->txtrs->ea.txtr || !ctx->sprite->sprite.txtr
		|| !ctx->txtrs->door.txtr)
		return (false);
	return (true);
}

bool	load_imgs(t_ctx	*ctx, char **paths)
{
	ctx->txtrs->no.img = mlx_new_image_from_file(ctx->render->mlx, paths[0],
			&ctx->txtrs->no.w, &ctx->txtrs->no.h);
	ctx->txtrs->so.img = mlx_new_image_from_file(ctx->render->mlx, paths[1],
			&ctx->txtrs->so.w, &ctx->txtrs->so.h);
	ctx->txtrs->we.img = mlx_new_image_from_file(ctx->render->mlx, paths[2],
			&ctx->txtrs->we.w, &ctx->txtrs->we.h);
	ctx->txtrs->ea.img = mlx_new_image_from_file(ctx->render->mlx, paths[3],
			&ctx->txtrs->ea.w, &ctx->txtrs->ea.h);
	ctx->sprite->sprite.img = mlx_new_image_from_file(ctx->render->mlx,
			paths[4], &ctx->sprite->sprite.w, &ctx->sprite->sprite.h);
	ctx->txtrs->door.img = mlx_new_image_from_file(ctx->render->mlx,
			paths[5], &ctx->txtrs->door.w, &ctx->txtrs->door.h);
	if (!ctx->txtrs->no.img || !ctx->txtrs->so.img || !ctx->txtrs->we.img
		|| !ctx->txtrs->ea.img || !ctx->sprite->sprite.img
		|| !ctx->txtrs->door.img)
		return (false);
	if (!make_txtrs(ctx))
		return (false);
	return (true);
}
