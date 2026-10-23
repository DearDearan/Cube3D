/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_chartype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 10:05:29 by rboutelo          #+#    #+#             */
/*   Updated: 2026/02/15 10:23:17 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isspace(int32_t c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

bool	ft_isalpha(int32_t c)
{
	if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
		return (0);
	return (1);
}

bool	ft_isdigit(int32_t c)
{
	if (c > '/')
		return ((c - '0') < 10);
	return (0);
}
