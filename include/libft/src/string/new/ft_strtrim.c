/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:29:46 by rboutelo          #+#    #+#             */
/*   Updated: 2026/02/16 06:02:21 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int32_t	find_start(char const *s1, char const *set)
{
	int32_t	strs;
	int32_t	seti;

	strs = -1;
	while (s1[++strs])
	{
		seti = 0;
		while (set[seti])
			if (set[seti++] == s1[strs])
				break ;
		if (set[seti - 1] != s1[strs])
			break ;
	}
	return (strs);
}

static int32_t	find_end(char const *s1, char const *set)
{
	int32_t	stri;
	int32_t	seti;

	stri = ft_strlen(s1);
	while (--stri >= 0)
	{
		seti = 0;
		while (set[seti])
			if (set[seti++] == s1[stri])
				break ;
		if (set[seti - 1] != s1[stri])
			break ;
	}
	return (stri);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int32_t		strs;
	int32_t		stri;
	char		*result;

	if (!set || !s1)
		return (NULL);
	strs = find_start(s1, set);
	stri = find_end(s1, set);
	result = ft_substr(s1, strs, stri + 1 - strs);
	return (result);
}
