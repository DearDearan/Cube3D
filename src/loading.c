/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 06:07:17 by lifranco          #+#    #+#             */
/*   Updated: 2026/09/22 06:01:05 by lifranco         ###   ########.fr       */
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
	pixels = ft_calloc(HEIGHT * WIDTH, sizeof(mlx_color));
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
	if (!ctx->txtrs->no.img || !ctx->txtrs->so.img || !ctx->txtrs->we.img
		|| !ctx->txtrs->ea.img)
		return (false);
	fill_txtr(ctx, &ctx->txtrs->no);
	fill_txtr(ctx, &ctx->txtrs->so);
	fill_txtr(ctx, &ctx->txtrs->we);
	fill_txtr(ctx, &ctx->txtrs->ea);
	if (!ctx->txtrs->no.txtr || !ctx->txtrs->so.txtr || !ctx->txtrs->we.txtr
		|| !ctx->txtrs->ea.txtr)
		return (false);
	return (true);
}
