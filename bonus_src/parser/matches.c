/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matches.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:50:46 by rboutelo          #+#    #+#             */
/*   Updated: 2026/10/22 10:16:54 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define TXTRS 0
#define SND 1

static bool	check_textures(char **matches, int *i, char **paths[2])
{
	if (!ft_strcmp(matches[*i], "NO"))
		paths[TXTRS][0] = matches[++*i];
	else if (!ft_strcmp(matches[*i], "SO"))
		paths[TXTRS][1] = matches[++*i];
	else if (!ft_strcmp(matches[*i], "WE"))
		paths[TXTRS][2] = matches[++*i];
	else if (!ft_strcmp(matches[*i], "EA"))
		paths[TXTRS][3] = matches[++*i];
	else if (!ft_strcmp(matches[*i], "SP"))
		paths[TXTRS][4] = matches[++*i];
	else if (!ft_strcmp(matches[*i], "DO"))
		paths[TXTRS][5] = matches[++*i];
	else
	{
		return (false);
	}
	return (true);
}

static bool	check_sounds(char **matches, int *i, char **paths[2])
{
	if (!ft_strcmp(matches[*i], "MU"))
		paths[SND][0] = matches[++*i];
	else if (!ft_strcmp(matches[*i], "FXO"))
		paths[SND][1] = matches[++*i];
	else if (!ft_strcmp(matches[*i], "FXC"))
		paths[SND][2] = matches[++*i];
	else if (!ft_strcmp(matches[*i], "FXF"))
		paths[SND][3] = matches[++*i];
	else
	{
		return (false);
	}
	return (true);
}

bool	check_matches(char **matches, t_ctx *res, int *i, char **paths[2])
{
	if (check_textures(matches, i, paths))
		return (true);
	else if (check_sounds(matches, i, paths))
		return (true);
	else if (!ft_strcmp(matches[*i], "F"))
	{
		errno = 0;
		res->txtrs->floor = get_rgb(matches[*i + 1],
				matches[*i + 2], matches[*i + 3]);
		if (errno == EINVAL)
			return (false);
		*i += 3;
	}
	else if (!ft_strcmp(matches[*i], "C"))
	{
		errno = 0;
		res->txtrs->ceiling = get_rgb(matches[*i + 1],
				matches[*i + 2], matches[*i + 3]);
		if (errno == EINVAL)
			return (false);
		*i += 3;
	}
	else
		return (false);
	return (true);
}
