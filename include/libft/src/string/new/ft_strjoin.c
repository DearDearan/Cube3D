/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:09:33 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int32_t	i;
	int32_t	j;
	char	*result;
	t_ptr	s1p;
	t_ptr	s2p;

	if (!s1 && !s2)
		return (NULL);
	s1p.ptr = (char *)s1;
	s2p.ptr = (char *)s2;
	if (!s1 | !s2)
	{
		result = ft_strdup((char *)(s1p.addr | s2p.addr));
		return (result);
	}
	result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while ((i++)[s1])
		(i - 1)[result] = (i - 1)[s1];
	while ((j++)[s2])
		(i + j - 2)[result] = (j - 1)[s2];
	return (result);
}

char	*ft_extend(char *to_extend, char *extender)
{
	const char	*oto_extend = to_extend;
	char		*result;
	char		*resultcpy;

	result = malloc((ft_strlen_until(to_extend, '\0')
				+ ft_strlen_until(extender, '\0') + 1) * sizeof(char));
	if (!result)
		return (NULL);
	resultcpy = result;
	if (to_extend)
	{
		while (*to_extend)
			*resultcpy++ = *to_extend++;
	}
	if (extender)
	{
		while (*extender)
			*resultcpy++ = *extender++;
	}
	*resultcpy = '\0';
	free((char *)oto_extend);
	return (result);
}
