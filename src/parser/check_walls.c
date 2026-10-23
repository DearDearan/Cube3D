/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                       ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀    */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 03:48:58 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/22 21:25:58 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟           */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_nonwall(char c)
{
	return (c && ft_strchr("0NEWS2B", c));
}

static bool	is_edge(t_map *m, size_t i)
{
	const size_t	x = i % m->w;
	const size_t	y = i / m->w;

	return (x == 0 || y == 0 || x == m->w - 1 || y == m->h - 1
		|| m->map[i - 1] == ' ' || m->map[i + 1] == ' '
		|| m->map[i - m->w] == ' ' || m->map[i + m->w] == ' ');
}

bool	check_walls(t_map *m)
{
	size_t	i;

	i = 0;
	while (m->map[i])
	{
		if (is_nonwall(m->map[i]) && is_edge(m, i))
		{
			ft_dprintf(2, "Error: Space inside map | Non-closed map edges.\n");
			return (false);
		}
		i++;
	}
	return (true);
}
