/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:11:02 by rboutelo          #+#    #+#             */
/*   Updated: 2026/02/28 02:05:42 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, uintmax_t n)
{
	uintmax_t	i;
	char		*dest_m;
	char		*src_c;

	if (!dest || !src)
		return (NULL);
	dest_m = (char *)dest;
	src_c = (char *)src;
	i = 0;
	while (i < n)
	{
		dest_m[i] = src_c[i];
		i++;
	}
	return (dest);
}
