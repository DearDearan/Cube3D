/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   based_on_existing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 06:17:50 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, uint32_t start, uintmax_t len)
{
	char		*sub;
	uintmax_t	sublen;
	uintmax_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
	{
		sub = ft_strdup("");
		return (sub);
	}
	slen = ft_strlen(&s[start]);
	if (len > slen)
		sublen = slen;
	else
		sublen = len;
	sub = ft_calloc(sublen + 1, sizeof(char));
	if (!sub)
		return (NULL);
	sub = ft_memcpy(sub, &s[start], sublen);
	return (sub);
}

char	*ft_strmapi(char const *s, char (*f)(uint, char))
{
	char		*result;
	uintmax_t	i;

	if (!s || !f)
		return (NULL);
	result = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i++] != '\0')
		result[i - 1] = f(i - 1, s[i - 1]);
	result[i - 1] = '\0';
	return (result);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*odup;

	if (!s)
		return (ft_calloc(1, sizeof(char)));
	dup = malloc((ft_strlen(s) + 1) * (sizeof(char)));
	if (!dup)
		return (NULL);
	odup = dup;
	while (*s != '\0')
		*odup++ = *s++;
	*odup++ = *s++;
	return (dup);
}

char	*ft_strndup(const char *s, uint64_t n)
{
	char	*dup;
	char	*odup;

	dup = malloc((n + 1) * (sizeof(char)));
	if (!dup)
		return (NULL);
	odup = dup;
	while (*s != '\0' && n--)
		*dup++ = *s++;
	*dup = '\0';
	return (odup);
}

// @doc ft_copy_env
// @kind func
// @desc Copies the char ** tab provided as env and returns the copy.
// @param env: char **, Pointer to the tab to copy.
// @returns char **
char	**ft_copy_env(const char **env)
{
	char	**result;
	char	**oresult;

	if (!env)
		return (ft_calloc(1, sizeof(char *)));
	else
		result = ft_calloc(ft_nt_tablen((void *)env) + 1, sizeof(char *));
	oresult = result;
	while (env && *env)
		*result++ = ft_strdup(*env++);
	return (oresult);
}
