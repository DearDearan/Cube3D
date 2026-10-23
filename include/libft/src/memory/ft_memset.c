/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:04:55 by rboutelo          #+#    #+#             */
/*   Updated: 2026/02/18 01:07:08 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int32_t c, uintmax_t n)
{
	uintmax_t	i;
	char		*s_att;

	s_att = (char *)s;
	i = 0;
	while (i < n)
	{
		s_att[i] = c;
		i++;
	}
	return (s);
}
