/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 06:17:36 by rboutelo          #+#    #+#             */
/*   Updated: 2026/10/22 10:01:36 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	free_parse(char *error, PEG *peg, char *fcontent, char **matches)
{
	if (error)
		ft_dprintf(2, error);
	ft_free_nt_tab(matches, MAX_MATCHES);
	free(fcontent);
	free_peg(peg);
	ft_clear_filelist();
	if (error)
		return (false);
	return (true);
}
