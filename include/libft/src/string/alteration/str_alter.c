/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_alter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 06:05:56 by rboutelo          #+#    #+#             */
/*   Updated: 2026/02/18 01:05:34 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(uint32_t, char*))
{
	int32_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i++] != '\0')
		f(i - 1, &s[i - 1]);
}

int32_t	ft_toupper(int32_t c)
{
	if (c > '`' && c < '{')
		return (c - ('a' - 'A'));
	return (c);
}

int32_t	ft_tolower(int32_t c)
{
	if (c > '@' && c < '[')
		return (c + ('a' - 'A'));
	return (c);
}

uintmax_t	ft_strlcpy(char *dst, const char *src, uintmax_t dsize)
{
	uintmax_t	i;

	i = 0;
	if (dsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < dsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

uintmax_t	ft_strlcat(char *dst, const char *src, uintmax_t dsize)
{
	const char	*odst = dst;
	const char	*osrc = src;
	uintmax_t	n;
	uintmax_t	dlen;

	n = dsize;
	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odst;
	n = dsize - dlen;
	if (n-- == 0)
		return (dlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - osrc));
}
