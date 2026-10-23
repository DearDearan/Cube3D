/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 02:02:37 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_file.h"

#ifdef AUTHORIZED_READV

intmax_t	ft_readv(int32_t fd, t_iovec *iov, uintmax_t cnt)
{
	const intmax_t	result = readv(fd, (struct iovec *)iov, cnt);

	return (result);
}
#else //AUTHORIZED_READV

intmax_t	perform_read(t_ffile fd, uintmax_t len, char **buf)
{
	intmax_t	result;

	*buf = malloc(len);
	if (!*buf)
		return (-1);
	result = read(fd, (*buf), len);
	if (result < 0)
	{
		free(*buf);
		*buf = NULL;
		return (-1);
	}
	return (result);
}

// @doc ft_readv
// @kind func
// @desc Fake readv, is more costly but still atomic (unless AUTHORIZED_READV).
// @param fd: [[t_ffile]], The fd that should be scatter read from.
// @param iov: [[t_iovec]] *, The iovecs to read to.
// @param cnt: int32_t, The number of iovec.
// @returns intmax_t, The amout of bytes read.
// Not calling readv because it is not authorized but mine is still atomic
intmax_t	ft_readv(t_ffile fd, t_iovec *iov, int32_t cnt)
{
	const uintmax_t	len = get_total_iov_len(iov, cnt);
	char			*tmp;
	const intmax_t	result = perform_read(fd, len, &tmp);
	int32_t			i;
	intmax_t		rem;

	if (cnt < 0 || result < 0)
		return (-1);
	rem = result;
	i = 0;
	while (i < cnt && rem > 0)
	{
		ft_memcpy(iov[cnt].iov_base, tmp, ft_min(iov[cnt].iov_len, rem));
		tmp += iov[cnt].iov_len;
		rem -= ft_min(iov[cnt].iov_len, result);
		i++;
	}
	free(tmp - len);
	return (result);
}
#endif //AUTHORIZED_READV
