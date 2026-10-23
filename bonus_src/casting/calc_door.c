/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 05:39:42 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/20 10:15:34 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_door_txtr_x(t_ctx *ctx, t_cast *cst)
{
	const t_img	curr = get_txtr_image(ctx, cst);
	int			i;

	i = get_door(cst->map.x, cst->map.y, ctx->doors, ctx->d_count);
	if (i < 0)
		return (0);
	return ((int)((cst->wall_x - ctx->doors[i].progress) * curr.w));
}

bool	handle_doors(t_ctx *ctx, t_cast *cst)
{
	int	i;

	i = get_door(cst->map.x, cst->map.y, ctx->doors, ctx->d_count);
	if (i < 0)
		return (false);
	calc_wall_dst(cst);
	calc_wall_x(cst);
	cst->is_door = ctx->doors[i].progress <= cst->wall_x;
	return (cst->is_door);
}
