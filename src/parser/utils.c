/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 03:41:53 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/21 13:30:55 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_color	get_rgb(char *r, char *g, char *b, t_map *map)
{
	const char	*clrs[3] = {r, g, b};
	mlx_color	res;
	int32_t		tmp;
	int8_t		i;

	i = 0;
	res.rgba = 255;
	while (i < 3)
	{
		tmp = ft_atol(clrs[i]);
		if (tmp > 255 || !ft_str_is_valid((void *)clrs[i], ft_isdigit))
		{
			map->error = true;
			ft_dprintf(2, "Error : %s", CLR_ERR);
			return ((mlx_color){0});
		}
		res.rgba += tmp << (8 * (3 - i));
		i++;
	}
	return (res);
}

void	init_map_width_height(char *map, t_map *resmap)
{
	uintmax_t	tmp;
	uintmax_t	i;

	resmap->w = 0;
	i = 0;
	while (map[i])
	{
		tmp = ft_strlen_until(&map[i], '\n');
		if (tmp > resmap->w)
			resmap->w = tmp;
		i += tmp + (map[i] == '\n');
	}
	i = 0;
	resmap->h = 1;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1])
			resmap->h += 1;
		i++;
	}
	resmap->map = malloc((resmap->w * resmap->h + 1) * sizeof(char));
	resmap->map[resmap->w * resmap->h] = 0;
	ft_memset(resmap->map, ' ', resmap->w * resmap->h * sizeof(char));
}

bool	handle_matches(char **matches, t_ctx *res)
{
	int		i;
	char	*txtr_paths[4];

	i = 0;
	while (matches[i])
	{
		if (!check_matches(matches, res, &i, txtr_paths))
			break ;
		i++;
	}
	if (res->map->error)
		return (false);
	if (!parse_text_path(res, txtr_paths))
		return (false);
	free(res->map);
	res->map = validate_map(matches[i], &res->player, &res->dir, &res->plane);
	if (!res->map)
	{
		ft_dprintf(2, "Error: Incorrect Map rules\n");
		return (false);
	}
	return (true);
}

bool	check_matches(char **matches, t_ctx *res, int *i, char **txtr_paths)
{
	if (!ft_strcmp(matches[*i], "NO"))
		txtr_paths[0] = matches[++*i];
	else if (!ft_strcmp(matches[*i], "SO"))
		txtr_paths[1] = matches[++*i];
	else if (!ft_strcmp(matches[*i], "WE"))
		txtr_paths[2] = matches[++*i];
	else if (!ft_strcmp(matches[*i], "EA"))
		txtr_paths[3] = matches[++*i];
	else if (!ft_strcmp(matches[*i], "F"))
	{
		res->txtrs->floor = get_rgb(matches[*i + 1],
				matches[*i + 2], matches[*i + 3], res->map);
		*i += 3;
	}
	else if (!ft_strcmp(matches[*i], "C"))
	{
		res->txtrs->ceiling = get_rgb(matches[*i + 1],
				matches[*i + 2], matches[*i + 3], res->map);
		*i += 3;
	}
	else
		return (false);
	if (res->map->error == true)
		return (false);
	return (true);
}

t_vec2	set_player(t_map *map, char *mpos, t_vec2 *dir, t_vec2 *plane)
{
	const uintmax_t	mposui = mpos - map->map;
	t_vec2			player;
	char			dir_char;	

	player.x = mposui % map->w + .5;
	player.y = mposui / map->w + .5;
	dir_char = *mpos;
	if (dir_char == 'N')
		*dir = (t_vec2){0.0, -1.0};
	if (dir_char == 'N')
		*plane = (t_vec2){1.0, 0.0};
	if (dir_char == 'S')
		*dir = (t_vec2){0.0, 1.0};
	if (dir_char == 'S')
		*plane = (t_vec2){-1.0, 0.0};
	if (dir_char == 'E')
		*dir = (t_vec2){1.0, 0.0};
	if (dir_char == 'E')
		*plane = (t_vec2){0.0, 1.0};
	if (dir_char == 'W')
		*dir = (t_vec2){-1.0, 0.0};
	if (dir_char == 'W')
		*plane = (t_vec2){0.0, -1.0};
	return (player);
}
