/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ffilelist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 21:59:22 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_file.h"

// @doc get_filelist
// @kind func
// @desc No. You don't get to access it, this ain't a global you sick fuck.
// @returns ¯\_(ツ)_/¯, Nope, I ain't giving you more info.
static t_ffile	*get_filelist(void)
{
	static t_ffile	filelist[FD_SETSIZE];

	return (filelist);
}

// @doc append_file
// @kind func
// @desc No, you still don't get to access it, you can but I don't want you to.
// @desc The only reason you can is because of some horrendous norm...
// @return ¯\_(ツ)_/¯, Nope, I ain't giving you more info.
void	append_file(t_ffile file)
{
	t_ffile *const	filelist = get_filelist();
	uint32_t		i;

	i = 0;
	while (i <= FD_SETSIZE)
	{
		if (!filelist[i] || filelist[i] < 0)
		{
			filelist[i] = file;
			return ;
		}
		i++;
	}
}

// @doc remove_file
// @kind func
// @desc No, you still don't get to access it, you can but I don't want you to.
// @desc The only reason you can is because of some horrendous norm...
// @return ¯\_(ツ)_/¯, Nope, I ain't giving you more info.
void	remove_file(t_ffile file)
{
	t_ffile *const	filelist = get_filelist();
	uint32_t		i;

	i = 0;
	while (i <= FD_SETSIZE)
	{
		if (filelist[i] == file)
		{
			filelist[i] = 0;
			return ;
		}
		i++;
	}
}

// @doc ft_clear_filelist
// @kind func
// @desc Closes all registered fds.
void	ft_clear_filelist(void)
{
	t_ffile *const	filelist = get_filelist();
	uint32_t		i;

	i = 0;
	while (i < FD_SETSIZE)
	{
		if (filelist[i] > 0)
		{
			close(filelist[i]);
			filelist[i] = -1;
		}
		i++;
	}
}
