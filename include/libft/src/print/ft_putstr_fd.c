/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:22:39 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @doc ft_putstr_fd
// @kind func
// @desc Prints the string s to the fd fd.
// @param s: const char *, String to print.
// @param fd: [[t_ffile]], fd to print to.
// @returns int32_t, number of chars written, negative on error.
int32_t	ft_putstr_fd(const char *s, t_ffile fd)
{
	int32_t	result;

	if (!s)
		return (0);
	result = write(fd, s, ft_strlen(s));
	return (result);
}

// @doc ft_putstrn_fd
// @kind func
// @desc Prints len characters from s to the fd fd.
// @param s: const char *, String to print.
// @param fd: [[t_ffile]], fd to print to.
// @param len: int32_t, number of characters to print.
// @returns int32_t, number of chars written, negative on error.
int32_t	ft_putstrn_fd(const char *s, int32_t fd, int32_t len)
{
	int32_t	result;

	if (!s)
		return (0);
	result = write(fd, s, ft_min(ft_strlen(s), len));
	return (result);
}

// @doc ft_putstr_fd_null
// @kind func
// @desc Prints the string s to the fd fd, formats NULL as `(null)`.
// @param s: const char *, String to print.
// @param fd: [[t_ffile]], fd to print to.
// @returns int32_t, number of chars written, negative on error.
int32_t	ft_putstr_fd_null(const char *s, t_ffile fd)
{
	int32_t	result;

	if (!s)
		result = write(fd, "(null)", 6);
	else
		result = write(fd, s, ft_strlen(s));
	return (result);
}
