/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 03:16:16 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/23 10:31:04 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define KEYS "{'NO'/'SO'/'WE'/'EA'}"
#define VALUE "[ \t]+{(!([ \t]*'\n'/'\r').)+}"
#define COLOR "{[FC]}[ \t]+"
#define NUM "{[0-9][0-9]?[0-9]?}"
#define COMMA "','"
#define BLANK "[ \t]*'\n'"
#define ROW "&(' '*'1')(!([ 1]('\n'/^))[01NEWS ])*[ 1]('\n'/^)"
#define TAIL "([ \t]*'\n')*[ \t]*^"

#define ACHR "01NEWS"

bool	parse_text_path(t_ctx *context, char **text_paths)
{
	char	*text_path;
	uint8_t	i;

	i = 0;
	while (i < 4)
	{
		text_path = text_paths[i];
		if (text_path[ft_strlen(text_path)] == '/')
			return (false);
		i++;
	}
	if (!load_imgs(context, text_paths))
	{
		ft_dprintf(2, "Error: An error has occured while %s\n",
			"loading the textures. Please verify the file path/extension.");
		return (false);
	}
	return (true);
}

t_map	*make_map(char *map, uintmax_t *ppos)
{
	t_map		*res;
	uintmax_t	utils[3];

	ft_bzero(utils, sizeof(utils));
	res = malloc(sizeof(t_map));
	init_map_width_height(map, res);
	while (map[utils[0]])
	{
		if (map[utils[0]] == '\n')
		{
			while (utils[1] % res->w != 0)
				utils[1]++;
			utils[0]++;
			continue ;
		}
		if (utils[0] == *ppos && !utils[2])
		{
			*ppos = utils[1];
			utils[2] = 1;
		}
		res->map[utils[1]++] = map[utils[0]++];
	}
	return (res);
}

t_map	*validate_map(char *map, t_vec2 *player, t_vec2 *dir, t_vec2 *plane)
{
	uintmax_t	i[2];
	t_map		*res;

	ft_memset(i, INT32_MAX, sizeof(i));
	while (map[++i[0]])
	{
		if (ft_strchr("0NEWS", map[i[0]]) && !ft_strchr(ACHR, map[i[0] + 1]))
			return (NULL);
		if (ft_strchr("NEWS", map[i[0]]) && i[1] == UINTMAX_MAX)
			i[1] = i[0];
		else if (ft_strchr("NEWS", map[i[0]]))
			return (NULL);
	}
	if ((!ft_strchr(map, 'N') && !ft_strchr(map, 'E')
			&& !ft_strchr(map, 'W') && !ft_strchr(map, 'S')))
		return (NULL);
	res = make_map(map, &i[1]);
	*player = set_player(res, res->map + i[1], dir, plane);
	if ((player->x < 0.0 && player->y < 0.0) || !check_walls(res))
	{
		free(res->map);
		free(res);
		return (NULL);
	}
	return (res);
}

bool	is_dot_cub(char *filename)
{
	return (ft_strlen(filename) >= 4
		&& !ft_strncmp(".cub", filename + (ft_strlen(filename) - 4), 4));
}

bool	parse_map(char *filename, t_ctx *res)
{
	char	*fcontent;
	PEG		*image_rule;
	char	**matches;

	image_rule = peg("("KEYS VALUE"/"COLOR NUM COMMA NUM COMMA NUM
			"/"BLANK")+{("ROW")+}"TAIL);
	res->txtrs = ft_calloc(1, sizeof(t_txtr));
	matches = ft_calloc(MAX_MATCHES, sizeof(char *));
	fcontent = NULL;
	if (!is_dot_cub(filename))
		return (free_parse(EXT_ERR, image_rule, fcontent, matches));
	ft_ffreadall(ft_ffopen(filename, "r"), (void *)&fcontent);
	if (!image_rule && !fcontent)
		return (free_parse(FLE_ERR, image_rule, fcontent, matches));
	match(image_rule, fcontent, matches);
	if (ft_nt_tablen((void *)matches) < 17 || !handle_matches(matches, res))
		return (free_parse(INV_ERR, image_rule, fcontent, matches));
	free_parse(NULL, image_rule, fcontent, matches);
	return (true);
}
