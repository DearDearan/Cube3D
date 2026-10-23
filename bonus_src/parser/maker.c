/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:50:35 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/22 10:12:04 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	make_door(t_ctx	*ctx, t_map *res, uintmax_t dpos)
{
	ctx->d_count += 1;
	ctx->doors = ft_recalloc(
			ctx->doors,
			(ctx->d_count - 1) * sizeof(t_door),
			ctx->d_count,
			sizeof(t_door));
	if (!ctx->doors)
	{
		ft_dprintf(2, "Error: Malloc Error");
		return (false);
	}
	ctx->doors[ctx->d_count - 1] = (t_door){.pos = (t_vec2i){
		.x = dpos % res->w,
		.y = dpos / res->w
	}};
	return (true);
}

bool	make_sprite(t_ctx *ctx, t_map *res, uintmax_t spos)
{
	if (ctx->sprite->pos.x != 0.0 || ctx->sprite->pos.y != 0.0)
	{
		ft_dprintf(2, "Error: Invalid Sprite Position\n");
		return (false);
	}
	ctx->sprite->pos = (t_vec2){
		.x = (spos % res->w) + .5,
		.y = (spos / res->w) + .5
	};
	return (true);
}

static bool	iter_map(t_map *res, t_ctx *ctx, char *map, uintmax_t *ppos)
{
	uintmax_t	i[3];

	ft_bzero(i, sizeof(i));
	while (map[i[0]])
	{
		if (map[i[0]] == '\n')
		{
			while (i[1] % res->w != 0)
				i[1]++;
			i[0]++;
			continue ;
		}
		if (map[i[0]] == '2' && !make_door(ctx, res, i[1]))
			return (false);
		if (map[i[0]] == 'B' && !make_sprite(ctx, res, i[1]))
			return (false);
		if (i[0] == *ppos && !i[2])
		{
			*ppos = i[1];
			i[2] = 1;
		}
		res->map[i[1]++] = map[i[0]++];
	}
	return (true);
}

t_map	*make_map(char *map, uintmax_t *ppos, t_ctx *ctx)
{
	t_map		*res;

	res = malloc(sizeof(t_map));
	if (!res)
		return (NULL);
	init_map_width_height(map, res);
	ctx->map = res;
	res->mini = mlx_new_image(ctx->render->mlx, MINMAP, MINMAP);
	if (!res->mini)
	{
		ft_dprintf(2, "Error: Minimap Image Error\n");
		mlx_destroy_image(ctx->render->mlx, res->mini);
		free(res);
		return (NULL);
	}
	if (!iter_map(res, ctx, map, ppos))
	{
		mlx_destroy_image(ctx->render->mlx, res->mini);
		free(res);
		return (NULL);
	}
	return (res);
}
