/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:20:36 by rboutelo          #+#    #+#             */
/*   Updated: 2026/02/18 01:06:57 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, uintmax_t n)
{
	uintmax_t	i;
	char		*dest_m;
	char		*src_c;

	dest_m = (char *)dest;
	src_c = (char *)src;
	i = n;
	if (src_c < dest_m)
		while (n > --i)
			dest_m[i] = src_c[i];
	else
		ft_memcpy(dest, src, n);
	return ((void *)dest_m);
}
