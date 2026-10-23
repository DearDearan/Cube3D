/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_micro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 06:38:28 by rboutelo          #+#    #+#             */
/*   Updated: 2026/10/05 01:12:54 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PEGGLE_DELUXE_SOURCES
#include "peggle_deluxe.h"

static bool	escape_if_necessary(char **str, char **res)
{
	if (*--*str == '\\' && !*++*str)
		return (false);
	*res = push_char(*res, *(*str)++);
	return (true);
}

char	*parse_lit(char **str)
{
	char	quote;
	char	*res;

	quote = *(*str)++;
	res = ft_calloc(1, sizeof(char));
	while (1)
	{
		if (!**str)
		{
			free(res);
			return (NULL);
		}
		if (*(*str)++ == quote)
			break ;
		if (!escape_if_necessary(str, &res))
		{
			free(res);
			return (NULL);
		}
	}
	return (res);
}

char	*parse_class(char **str)
{
	char	*res;
	char	s;

	res = ft_calloc(1, sizeof(char));
	while (*++(*str))
	{
		if (**str == ']' && (*str)++)
			break ;
		if (*(*str + 1) == '-' && *(*str + 2) != ']')
		{
			s = **str - 1;
			(*str) += 2;
			while (++s != **str + 1)
			{
				res = ft_recalloc(res, LEN(res), LEN(res) + 2, sizeof(char));
				res[LEN(res)] = s;
			}
			continue ;
		}
		res = ft_recalloc(res, LEN(res), LEN(res) + 2, sizeof(char));
		res[LEN(res)] = **str;
	}
	return (res);
}
