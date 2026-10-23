/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 10:05:29 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const
	t_validator_fn g_validators[] = {
[DIGIT] = ft_isdigit, [ALPHA] = ft_isalpha,
[SPACE] = ft_isspace, [PRINT] = ft_isprint,
[ASCII] = ft_isascii, [ALNUM] = ft_isalnum
};

bool	ft_str_is_valid(char *str, t_validator_fn validator)
{
	bool	result;

	result = true;
	while (*str && result)
	{
		result = validator(*str);
		str++;
	}
	return (result);
}
