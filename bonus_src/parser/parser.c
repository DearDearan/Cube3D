/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                            ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀    */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 03:16:16 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/22 21:06:12 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟           */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define KEYS "{'NO'/'SO'/'WE'/'EA'/'DO'/'SP'/'MU'/'FXO'/'FXC'/'FXF'}"
#define VALUE "[ \t]+{(!([ \t]*'\n'/'\r').)+}"
#define COLOR "{[FC]}[ \t]+"
#define NUM "{[0-9][0-9]?[0-9]?}"
#define COMMA "','"
#define BLANK "[ \t]*'\n'"
#define ROW "&(' '*'1')(!([ 1]('\n'/^))[012BNEWS ])*[ 1]('\n'/^)"
#define TAIL "([ \t]*'\n')*[ \t]*^"

#define ALLCHR "01NEWS2B"
#define ALLNW "0NEWS2B"

bool	check_snd_path(char **snds)
{
	int		i;
	char	*snd_path;

	i = 0;
	while (i < 4)
	{
		snd_path = snds[i];
		if (!snd_path || snd_path[ft_strlen(snd_path) - 1] == '/')
			return (false);
		i++;
	}
	return (true);
}

bool	parse_text_path(t_ctx *context, char **text_paths, char **snds)
{
	if (!load_imgs(context, text_paths))
	{
		ft_dprintf(2, "Error: An error has occured while %s\n",
			"loading the textures. Please verify the file extension/path.");
		return (false);
	}
	else if (!check_snd_path(snds) || !fill_ms_sfx(context, snds))
	{
		ft_dprintf(2, "Error: An error has occured while %s\n",
			"loading the music and sounds. Verifiy the file extension/path");
		return (false);
	}
	return (true);
}

static bool	validate_special_chars(char *map)
{
	return (ft_strchr(map, 'B') != ft_strrchr(map, 'B')
		|| (!ft_strchr(map, 'N') && !ft_strchr(map, 'E')
			&& !ft_strchr(map, 'W') && !ft_strchr(map, 'S')));
}

t_map	*validate_map(char *map, t_vec2 *p_dat[3], t_ctx *ctx)
{
	uintmax_t	i[2];
	t_map		*res;

	ft_memset(i, UINT32_MAX, sizeof(i));
	while (map[++i[0]])
	{
		if (ft_strchr(ALLNW, map[i[0]]) && !ft_strchr(ALLCHR, map[i[0] + 1]))
			return (NULL);
		if (ft_strchr("NEWS", map[i[0]]) && i[1] == UINTMAX_MAX)
			i[1] = i[0];
		else if (ft_strchr("NEWS", map[i[0]]))
			return (NULL);
	}
	if (validate_special_chars(map))
		return (NULL);
	res = make_map(map, &i[1], ctx);
	*(p_dat[0]) = set_player(res, res->map + i[1], p_dat[1], p_dat[2]);
	if ((p_dat[0]->x < 0.0 && p_dat[0]->y < 0.0) || !check_walls(res))
	{
		mlx_destroy_image(ctx->render->mlx, res->mini);
		free(res->map);
		free(res);
		return (NULL);
	}
	return (res);
}

bool	parse_map(char *filename, t_ctx *res)
{
	char	*fcontent;
	PEG		*image_rule;
	char	**matches;

	image_rule = peg("("KEYS VALUE"/"COLOR NUM COMMA NUM COMMA NUM
			"/"BLANK")+{("ROW")+}"TAIL);
	matches = ft_calloc(MAX_MATCHES + 1, sizeof(char *));
	fcontent = NULL;
	if (!is_dot_cub(filename))
		return (free_parse(EXT_ERR, image_rule, fcontent, matches));
	ft_ffreadall(ft_ffopen(filename, "r"), (void *)&fcontent);
	if (!image_rule || !fcontent)
		return (free_parse(FLE_ERR, image_rule, fcontent, matches));
	match(image_rule, fcontent, matches);
	if (ft_nt_tablen((void *)matches) != (uintmax_t)29
		|| !handle_matches(matches, res))
		return (free_parse(INV_ERR, image_rule, fcontent, matches));
	free_parse(NULL, image_rule, fcontent, matches);
	return (true);
}
