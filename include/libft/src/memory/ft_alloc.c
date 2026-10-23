/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:31:48 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(uintmax_t nmemb, uintmax_t size)
{
	char	*ptr;

	if (size != 0 && nmemb > ((uintmax_t)-1 / size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return ((void *)ptr);
}

void	*ft_realloc(void *ptr, uintmax_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	ft_memcpy(new_ptr, ptr, ft_min(ft_strlen(ptr), size));
	free(ptr);
	return (new_ptr);
}

void	*ft_recalloc(void *ptr, uintmax_t old, uintmax_t nmemb, uintmax_t size)
{
	void		*new_ptr;

	new_ptr = ft_calloc(nmemb, size);
	ft_memcpy(new_ptr, ptr, ft_min(old, nmemb * size));
	free(ptr);
	return (new_ptr);
}

void	*ft_free_nt_tab(char **str, const int32_t alloc_count)
{
	int32_t	i;

	i = 0;
	while (str && str[i] && i < alloc_count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
