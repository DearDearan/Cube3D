/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 17:11:16 by lifranco          #+#    #+#             */
/*   Updated: 2026/09/23 03:23:32 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cast(t_cast *cast, t_ctx *ctx, int screen_x)
{
	double	camera_x;

	camera_x = 2 * screen_x / (double)WIDTH - 1;
	cast->origin.x = ctx->player.x;
	cast->origin.y = ctx->player.y;
	cast->dir.x = ctx->dir.x + ctx->plane.x * camera_x;
	cast->dir.y = ctx->dir.y + ctx->plane.y * camera_x;
	calc_map_and_deltas(cast);
	calc_dist_and_step(cast);
}

void	calc_dist_and_step(t_cast *cast)
{
	if (cast->dir.x < 0)
	{
		cast->step.x = -1;
		cast->side_dist.x = (cast->origin.x - cast->map.x) * cast->delta.x;
	}
	else
	{
		cast->step.x = 1;
		cast->side_dist.x = (cast->map.x + 1 - cast->origin.x) * cast->delta.x;
	}
	if (cast->dir.y < 0)
	{
		cast->step.y = -1;
		cast->side_dist.y = (cast->origin.y - cast->map.y) * cast->delta.y;
	}
	else
	{
		cast->step.y = 1;
		cast->side_dist.y = (cast->map.y + 1 - cast->origin.y) * cast->delta.y;
	}
}

void	calc_map_and_deltas(t_cast *cast)
{
	cast->map.x = floor(cast->origin.x);
	cast->map.y = floor(cast->origin.y);
	cast->delta.x = fabs(1 / cast->dir.x);
	cast->delta.y = fabs(1 / cast->dir.y);
	if (cast->delta.x == 0)
		cast->delta.x = 0.01;
	if (cast->delta.y == 0)
		cast->delta.y = 0.01;
}
