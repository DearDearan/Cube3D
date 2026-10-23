/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:43:19 by rboutelo          #+#    #+#             */
/*   Updated: 2026/02/18 01:06:26 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int32_t c, uintmax_t n)
{
	uintmax_t	i;
	char		*result;

	result = (char *)s;
	i = 0;
	while (i < n)
	{
		if (((unsigned char) result[i++]) == ((unsigned char) c))
			return (&result[--i]);
	}
	return (NULL);
}
