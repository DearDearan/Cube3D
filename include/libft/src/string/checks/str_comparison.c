/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_comparison.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 06:10:56 by rboutelo          #+#    #+#             */
/*   Updated: 2026/02/28 02:06:20 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int32_t	ft_strncmp(const char *s1, const char *s2, int32_t n)
{
	int32_t	diff;

	if (n == 0)
		return (0);
	while (n-- != 0)
	{
		diff = *(unsigned char *)s1 - *(unsigned char *)(++s2 - 1);
		if (diff != 0)
			return (diff);
		if (!*s1++)
			break ;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, uintmax_t len)
{
	uintmax_t	i;
	int32_t		j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (little[j] == big[i + j] && (i + j) < len)
		{
			if (little[j] == '\0' || little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
