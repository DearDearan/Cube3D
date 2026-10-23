/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:41:33 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @doc ft_putnbr_fd
// @kind func
// @desc Prints the number n to the fd fd.
// @param n: int32_t, Number to print.
// @param fd: [[t_ffile]], fd to print to.
// @returns int32_t, number of chars written, negative on error.
int32_t	ft_putnbr_fd(int32_t n, t_ffile fd)
{
	int32_t	result;
	int64_t	nb;

	result = 0;
	nb = n;
	if (n < 0)
	{
		result += ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
		result += ft_putnbr_fd(nb / 10, fd);
	result += ft_putchar_fd(nb % 10 + '0', fd);
	return (result);
}
