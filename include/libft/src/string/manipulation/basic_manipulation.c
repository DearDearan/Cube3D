/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 06:13:13 by rboutelo          #+#    #+#             */
/*   Updated: 2026/03/09 22:47:16 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int32_t c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

uintmax_t	ft_strlen(const char *str)
{
	uintmax_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

uintmax_t	ft_strlen_until(const char *str, char c)
{
	const char	*ostr = str;

	while (str && *str && *str != c)
		str++;
	return (str - ostr);
}

uint64_t	ft_fwlen(const char *str)
{
	uint64_t	i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int32_t c)
{
	char	*lo;

	lo = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			lo = (char *)s;
		s++;
	}
	if (*s == (char)c)
		lo = (char *)s;
	return (lo);
}
