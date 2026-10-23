/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:36:19 by lifranco          #+#    #+#             */
/*   Updated: 2026/09/09 04:19:56 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	get_tile(t_map *map, uintmax_t x, uintmax_t y)
{
	if (x >= map->w || y >= map->h)
		return ('\0');
	return (map->map[y * map->w + x]);
}

int	calc_tile(t_map *map, uintmax_t x, uintmax_t y)
{
	return (y * map->w + x);
}

void	set_tile(char tile, t_vec2i vec, t_map *map)
{
	map->map[calc_tile(map, vec.x, vec.y)] = tile;
}
