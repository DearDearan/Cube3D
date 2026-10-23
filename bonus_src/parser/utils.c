/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                             ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀    */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 03:41:53 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/22 20:44:24 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟           */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_color	get_rgb(char *r, char *g, char *b)
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
		if (tmp > 255 || tmp < 0
			|| !ft_str_is_valid((void *)clrs[i], ft_isdigit))
		{
			errno = EINVAL;
			ft_dprintf(2, CLR_ERR);
			return ((mlx_color){0});
		}
		res.rgba += tmp << (8 * (3 - i));
		i++;
	}
	return (res);
}

bool	is_dot_cub(char *filename)
{
	return (ft_strlen(filename) >= 4
		&& !ft_strncmp(".cub", filename + (ft_strlen(filename) - 4), 4));
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
	char	*txtr_paths[6];
	char	*snd_paths[4];
	char	**paths[2];

	i = 0;
	ft_bzero(txtr_paths, sizeof(txtr_paths));
	ft_bzero(snd_paths, sizeof(snd_paths));
	paths[0] = txtr_paths;
	paths[1] = snd_paths;
	while (matches[i])
	{
		if (!check_matches(matches, res, &i, paths))
			break ;
		i++;
	}
	if (!parse_text_path(res, txtr_paths, snd_paths))
		return (false);
	free(res->map);
	res->map = validate_map(matches[i], (t_vec2 *[3]){&res->player,
			&res->dir, &res->plane}, res);
	if (!res->map)
		return (false);
	return (true);
}

t_vec2	set_player(t_map *map, char *mpos, t_vec2 *dir, t_vec2 *plane)
{
	const uintmax_t	mposui = mpos - map->map;
	const char		dir_char = *mpos;	
	t_vec2			player;

	if (!ft_strchr("NEWS", dir_char) || !dir_char)
		return ((t_vec2){-1.0, -1.0});
	player.x = mposui % map->w + .5;
	player.y = mposui / map->w + .5;
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
