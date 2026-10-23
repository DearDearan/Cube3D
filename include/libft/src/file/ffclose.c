/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffclose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 23:10:57 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_file.h"

// @doc ft_ffclose
// @kind func
// @desc Closes a [[t_ffile]]. (close the fd and unregister it)
// @param file: [[t_ffile]], The targeted file.
void	ft_ffclose(t_ffile *file)
{
	if (*file < 0)
		return ;
	remove_file(*file);
	close(*file);
	*file = -1;
}

// @doc ft_close_pipe
// @kind func
// @desc Closes a pipe (preeferably opened with ft_pipe).
// @param fds: [[t_ffile]][2], The pipe that needs to be closed.
void	ft_close_pipe(t_ffile fds[2])
{
	ft_ffclose(&fds[RE]);
	ft_ffclose(&fds[WE]);
}
