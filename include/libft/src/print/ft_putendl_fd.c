/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:36:04 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @doc ft_putendl_fd
// @kind func
// @desc Basically same as libc's puts but writes to an arbitrary fd.
// @param s: const char *, the string to write.
// @param fd: [[t_ffile]], the fd to write to.
// @returns int32_t, number of printed chars, negative on error.
int32_t	ft_putendl_fd(const char *s, t_ffile fd)
{
	int32_t	result;

	if (!s)
		return (0);
	result = ft_putstr_fd(s, fd);
	result += ft_putchar_fd('\n', fd);
	return (result);
}

// @doc ft_putendl_fd
// @kind func
// @desc Basically same as ft_putendl_fd but formats NULL as `(null)`.
// @param s: const char *, the string to write.
// @param fd: [[t_ffile]], the fd to write to.
// @returns int32_t, number of printed chars, negative on error.
int32_t	ft_putendl_fd_null(const char *s, int32_t fd)
{
	int32_t	result;

	result = ft_putstr_fd_null(s, fd);
	result += ft_putchar_fd('\n', fd);
	return (result);
}

// @doc ft_puts
// @kind func
// @desc Basically same as libc's puts.
// @param s: char *, the string to write.
// @returns int32_t, number of printed chars, negative on error.
int32_t	ft_puts(char *s)
{
	int32_t	result;

	result = ft_putendl_fd(s, STDOUT_FILENO);
	return (result);
}
