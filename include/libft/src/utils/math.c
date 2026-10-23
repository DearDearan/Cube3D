/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:50:54 by rboutelo          #+#    #+#             */
/*   Updated: 2026/10/20 04:14:14 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @doc ft_min
// @kind func
// @desc Returns the smallest unsigned between a and b.
// @param a: uintmax_t, First number to compare.
// @param b: uintmax_t, Second number to compare.
// @returns uintmax_t, Minimum of a and b.
uintmax_t	ft_min(uintmax_t a, uintmax_t b)
{
	if (a < b)
		return (a);
	return (b);
}

// @doc ft_max
// @kind func
// @desc Returns the biggest unsigned between a and b.
// @param a: uintmax_t, First number to compare.
// @param b: uintmax_t, Second number to compare.
// @returns uintmax_t, Maximum of a and b.
uintmax_t	ft_max(uintmax_t a, uintmax_t b)
{
	if (a > b)
		return (a);
	return (b);
}

// @doc ft_dmin
// @kind func
// @desc Returns the smallest double between a and b.
// @param a: double, First number to compare.
// @param b: double, Second number to compare.
// @returns double, Minimum of a and b.
double	ft_dmin(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

// @doc ft_dmax
// @kind func
// @desc Returns the biggest double between a and b.
// @param a: double, First number to compare.
// @param b: double, Second number to compare.
// @returns double, Maximum of a and b.
double	ft_dmax(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

// @doc ft_nt_tablen
// @kind func
// @desc Returns the length of the null terminated tab tab.
// @param tab: void **, Null terminated tab to get the length of.
// @returns uintmax_t, length of tab.
uintmax_t	ft_nt_tablen(void **tab)
{
	uintmax_t	len;

	len = 0;
	while (tab && tab[len])
		len++;
	return (len);
}
