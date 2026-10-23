/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcntl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:34:55 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syscalls.h"

#ifdef AUTHORIZED_FCNTL

int32_t	ft_fcntl(t_ffile fd, int32_t cmd, int32_t flags)
{
	const int32_t	result = fcntl(fd, cmd, flags);

	return (result);
}
#else //AUTHORIZED_FCNTL

// @doc ft_fcntl
// @kind func
// @desc Fake fcntl, does nothing unless AUTHORIZED_FCNTL is set.
// @param fd: t_ffile, The fd that *would* be targeted by fd.
// @param cmd: int32_t, The thing that *would* be done.
// @param flags: int32_t, The flags to apply, this was hardcoded for ft_fopen.
// @returns int32_t, Always 0 (unless AUTHORIZED_FCNTL) is set ofc.
// I don't call fcntl because it's not authorized so yea, void everything...
int32_t	ft_fcntl(t_ffile fd, int32_t cmd, int32_t flags)
{
	(void)fd;
	(void)cmd;
	(void)flags;
	return (0);
}
#endif //AUTHORIZED_FCNTL
