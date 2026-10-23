/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:00:56 by rboutelo          #+#    #+#             */
/*   Updated: 2026/02/18 01:06:34 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_memcmp(const void *s1, const void *s2, uintmax_t n)
{
	uintmax_t		i;
	unsigned char	*s1c;
	unsigned char	*s2c;

	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (s1c[i] != s2c[i])
			return (s1c[i] - s2c[i]);
		i++;
	}
	return (0);
}
