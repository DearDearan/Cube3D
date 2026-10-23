/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:16:43 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @doc ft_putchar_fd
// @kind func
// @desc Prints the character c to the fd fd.
// @param c: char, Character to print.
// @param fd: [[t_ffile]], fd to print to.
// @returns int32_t, number of chars written, negative on error.
int32_t	ft_putchar_fd(char c, t_ffile fd)
{
	int32_t	result;

	result = write(fd, &c, 1);
	return (result);
}
