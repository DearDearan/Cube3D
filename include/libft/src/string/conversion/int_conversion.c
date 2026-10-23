/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:25:06 by rboutlo           #+#    #+#             */
/*   Updated: 2026/09/22 12:49:26 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_atoi(const char *str)
{
	int64_t		result;
	int8_t		negative;
	int32_t		i;

	negative = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		negative = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = 0;
	while (ft_isdigit(str[i]) && result < INT32_MAX)
		result = (result * 10) + (str[i++] - '0');
	if (result > INT32_MAX + negative)
		errno = EINVAL;
	if (negative)
		return (-result);
	return (result);
}

static void	ft_rev(char *str, uintmax_t isnegative)
{
	uintmax_t	j;
	char		tmp;

	j = ft_strlen(str) - 1;
	while (j > isnegative)
	{
		tmp = str[isnegative];
		str[isnegative] = str[j];
		str[j] = tmp;
		j--;
		isnegative++;
	}
}

static int32_t	get_10_pow(int64_t value)
{
	int32_t	i;

	i = 0;
	while (value > 0)
	{
		++i;
		value /= 10;
	}
	return (i - 1);
}

int32_t	ft_atoi_base(char *str, char *base)
{
	uintmax_t	i[2];
	int32_t		sign;
	int32_t		res;

	i[0] = 0;
	sign = 1;
	res = 0;
	while (str[i[0]] == ' ' || str[i[0]] == '\t' || str[i[0]] == '\n'
		|| str[i[0]] == '\v' || str[i[0]] == '\f' || str[i[0]] == '\r')
		i[0]++;
	if (str[i[0]] == '-' || str[i[0]] == '+')
		if (str[i[0]++] == '-')
			sign = -1;
	while (str[i[0]])
	{
		i[1] = 0;
		while (i[1] < ft_strlen(base) && base[i[1]] != str[i[0]])
			i[1]++;
		if (i[1] == ft_strlen(base))
			break ;
		res = res * ft_strlen(base) + i[1];
		i[0]++;
	}
	return (res * sign);
}

char	*ft_itoa(int32_t n)
{
	int32_t	i;
	int64_t	nb;
	char	*result;
	int8_t	negative;

	nb = n;
	negative = nb < 0;
	if (negative)
		nb = -nb;
	if (n == 0)
		result = ft_strdup("0");
	else
		result = ft_calloc(negative + get_10_pow(nb) + 1 + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	if (negative)
		result[i++] = '-';
	while (nb > 0)
	{
		result[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	ft_rev(result, negative);
	return (result);
}
