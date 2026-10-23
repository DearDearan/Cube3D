/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 02:56:27 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_file.h"
#include "syscalls.h"

#ifdef AUTHORIZED_WRITEV

intmax_t	ft_writev(int fd, const t_iovec *iov, int cnt)
{
	const intmax_t	ret = writev(fd, iov, cnt);

	return (ret);
}
#else //AUTHORIZED_WRITEV

// @doc ft_writev
// @kind func
// @desc Fake writev, Mallocs but is still atomic (unless AUTHORIZED_WRITEV).
// @param fd: [[t_ffile]], The fd that *would* be targeted by fd.
// @param iov: const [[t_iovec]] *, The iovecs to gather write from.
// @param cnt: int32_t, The number of iovec to write from.
// @returns intmax_t, The number of byte wrote.
// I don't call writev because it's not authorized but mine is still atomic.
intmax_t	ft_writev(t_ffile fd, const t_iovec *iov, int32_t cnt)
{
	const uintmax_t	len = get_total_iov_len(iov, cnt);
	int32_t			i;
	char			*tmp;
	char			*otmp;
	intmax_t		res;

	if (cnt < 0)
		return (-1);
	tmp = malloc(len);
	if (!tmp)
		return (-1);
	otmp = tmp;
	i = 0;
	while (i < cnt)
	{
		ft_memcpy(iov[cnt].iov_base, tmp, iov[cnt].iov_len - 1);
		((char *)iov[cnt].iov_base)[iov[cnt].iov_len - 1] = '\0';
		i++;
		tmp += iov[cnt].iov_len;
	}
	res = write(fd, tmp, len);
	free(otmp);
	return (res);
}

#endif //AUTHORIZED_WRITEV
