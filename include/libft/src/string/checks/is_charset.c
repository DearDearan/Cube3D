/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_charset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 10:05:05 by rboutelo          #+#    #+#             */
/*   Updated: 2026/02/15 10:37:46 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isprint(int32_t c)
{
	return (c >= ' ' && c <= '~');
}

bool	ft_isascii(int32_t c)
{
	return ((uint32_t)c < 128);
}

bool	ft_isalnum(int32_t c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
