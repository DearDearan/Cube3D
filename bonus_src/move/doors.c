/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 04:41:00 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/02 01:54:49 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_door(int x, int y, t_door *doors, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (doors[i].pos.x == x && doors[i].pos.y == y)
			return (i);
		i++;
	}
	return (-1);
}

void	progress(t_door *door, bool prog)
{
	if (prog)
		door->progress += 0.05;
	else
		door->progress -= 0.05;
	if (door->progress > 1)
		door->progress = 1;
	if (door->progress < 0)
		door->progress = 0;
}

void	upd_doors(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->d_count)
	{
		progress(&ctx->doors[i], ctx->doors[i].open);
		if (ctx->doors[i].progress == 1)
			ctx->doors[i].open = true;
		else if (ctx->doors[i].progress == 0.0)
			ctx->doors[i].open = false;
		i++;
	}
}
