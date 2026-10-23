/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                          ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀    */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:30:58 by rboutelo          #+#    #+#             */
/*   Updated: 2026/09/24 05:00:37 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟           */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int32_t	count_strs(char const *s, const char c)
{
	int32_t	i;
	int32_t	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static uintmax_t	get_cur_len(char const *str, const char c,
	bool preserve_mode)
{
	uintmax_t	i;
	uintmax_t	j;

	j = 0;
	while (str[j] == c)
		j++;
	i = 0;
	while (str[j] != c && str[j])
	{
		j++;
		i++;
	}
	if (preserve_mode)
	{
		while (str[j] && str[j] == c)
		{
			j++;
			i++;
		}
	}
	return (i);
}

static bool	write_tab(char **tab, char const *s, char c, bool preserve_mode)
{
	uintmax_t	i;
	uintmax_t	j;
	int32_t		strc;

	j = 0;
	strc = 0;
	while (s[j])
	{
		i = get_cur_len(&s[j], c, preserve_mode);
		while (s[j] == c)
			j++;
		if (s[j] == '\0' && s[j - 1] == c)
			break ;
		tab[strc] = ft_substr(&s[j], 0, i);
		if (!tab[strc++])
		{
			ft_free_nt_tab(tab, strc - 1);
			return (true);
		}
		j = j + i;
	}
	return (false);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int32_t	strc;
	bool	error;

	if (!s)
		return (NULL);
	strc = count_strs(s, c);
	result = ft_calloc(strc + 1, sizeof(char *));
	if (!result)
		return (NULL);
	error = write_tab(result, s, c, false);
	if (error)
		return (NULL);
	return (result);
}

char	**ft_preserving_split(char const *s, char c)
{
	char	**result;
	int32_t	strc;
	bool	error;

	if (!s)
		return (NULL);
	strc = count_strs(s, c);
	result = ft_calloc(strc + 1, sizeof(char *));
	if (!result)
		return (NULL);
	error = write_tab(result, s, c, true);
	if (error)
		return (NULL);
	return (result);
}
