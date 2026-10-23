/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 14:31:49 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/20 10:01:34 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_wall_x(t_cast *cst)
{
	double	hit_x;
	double	hit_y;

	hit_x = cst->origin.x + cst->wall_dst * cst->dir.x;
	hit_y = cst->origin.y + cst->wall_dst * cst->dir.y;
	if (cst->side)
		cst->wall_x = hit_x - floor(hit_x);
	else
		cst->wall_x = hit_y - floor(hit_y);
}

void	calc_wall_dst(t_cast *cst)
{
	if (cst->side == false)
	{
		cst->wall_dst = cst->side_dist.x - cst->delta.x;
		if (cst->step.x == -1)
			cst->touched = WE;
		else
			cst->touched = EA;
	}
	else
	{
		cst->wall_dst = cst->side_dist.y - cst->delta.y;
		if (cst->step.y == -1)
			cst->touched = NO;
		else
			cst->touched = SO;
	}
}

static void	choose_side(t_cast *cast)
{
	if (cast->side_dist.x < cast->side_dist.y)
	{
		cast->side_dist.x += cast->delta.x;
		cast->map.x += cast->step.x;
		cast->side = false;
	}
	else
	{
		cast->side_dist.y += cast->delta.y;
		cast->map.y += cast->step.y;
		cast->side = true;
	}
}

static bool	send_ray(t_ctx *con, t_cast *cast)
{
	char	tile;

	cast->touched = NONE;
	cast->is_door = false;
	while (cast->in_render < (con->map->w + con->map->h) - 1)
	{
		cast->in_render++;
		choose_side(cast);
		tile = get_tile(con->map, cast->map.x, cast->map.y);
		if (tile == '1' || (tile == '2' && handle_doors(con, cast))
			|| (tile == '2' && cast->interact))
			return (true);
	}
	return (false);
}

void	raycast(t_ctx *con, t_cast *cast, int screen_x)
{
	bool	has_touched;

	cast->in_render = 0;
	cast->wall_dst = 0;
	cast->wall_x = 0;
	init_cast(cast, con, screen_x);
	has_touched = send_ray(con, cast);
	calc_wall_dst(cast);
	calc_wall_x(cast);
	if (!has_touched)
		cast->wall_dst = INFINITY;
}
