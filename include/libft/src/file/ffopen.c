/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffopen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 21:48:34 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_file.h"

// @doc fmodeflags
// @kind func
// @desc Yoinked from musl with some norm shaped adjustments.
// @param mode: const char *, The mode string.
// @returns int32_t, The value corresponding to the provided flags.
static int32_t	fmodeflags(const char *mode)
{
	int32_t	flags;

	if (ft_strchr(mode, '+'))
		flags = O_RDWR;
	else if (*mode == 'r')
		flags = O_RDONLY;
	else
		flags = O_WRONLY;
	if (ft_strchr(mode, 'x'))
		flags |= O_EXCL;
	if (ft_strchr(mode, 'e'))
		flags |= O_CLOEXEC;
	if (*mode != 'r')
		flags |= O_CREAT;
	if (*mode == 'w')
		flags |= O_TRUNC;
	if (*mode == 'a')
		flags |= O_APPEND;
	return (flags);
}

// @doc ft_ffopen
// @kind func
// @desc Fake fopen, actually just an open with extra steps.
// @param filename: char *, Name of the file to open.
// @param mode: const char *, Mode in which to open the file.
// @returns [[t_ffile]], The opened file's fd.
t_ffile	ft_ffopen(char *filename, const char *mode)
{
	t_ffile	file;
	int32_t	flags;

	flags = fmodeflags(mode);
	file = open(filename, flags, 0666);
	if (file < 0)
		return (-1);
	append_file(file);
	return (file);
}

// @doc ft_to_ffile
// @kind func
// @desc Registers an fd as though it was opened with ft_ffopen.
// @param fd: [[t_ffile]], fd to register.
// @returns [[t_ffile]], The registered fd (identical).
t_ffile	ft_to_ffile(t_ffile fd)
{
	t_ffile	file;

	file = fd;
	append_file(file);
	return (file);
}

// @doc ft_pipe
// @kind func
// @desc Does the same thing as pipe but registers the fds.
// @param fds: [[t_ffile]][2], The target in which to put the pipe.
// @returns int32_t, Same return code as pipe. 
int32_t	ft_pipe(t_ffile fds[2])
{
	int32_t	res;
	int32_t	err;

	res = pipe(fds);
	err = errno;
	if (!res)
	{
		ft_to_ffile(fds[0]);
		ft_to_ffile(fds[1]);
	}
	errno = err;
	return (res);
}
