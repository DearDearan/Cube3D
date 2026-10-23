/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 23:33:28 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/15 06:15:05 by rboutelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	in_set(char c)
{
	return (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'p' || c == '%');
}

int32_t	get_next(const char *format, bool *error)
{
	int32_t	next;

	next = 0;
	if (*format == '%')
	{
		next++;
		while (!in_set(*(format + next)) && *(format + next))
			next++;
		if (!*format && !in_set(*(format - 1)))
			*error = true;
		next++;
	}
	else
	{
		while (*(format + next) != '%' && *(format + next))
			next++;
	}
	return (next);
}

int32_t	print_pointer(void *pointer, t_ffile fd, bool *error)
{
	int32_t	result;

	if (!pointer)
		result = ft_putstr_fd("(nil)", fd);
	else
	{
		result = ft_putstr_fd("0x", fd);
		result += ft_putuint_base_fd((uintptr_t)pointer,
				"0123456789abcdef", fd, error);
	}
	return (result);
}

int32_t	inject(const char *format, va_list args, bool *error, t_ffile fd)
{
	int32_t	local_write;
	char	*b;

	local_write = -1;
	if (*(format + 1) == '%')
		local_write = ft_putchar_fd('%', fd);
	else if (*(format + 1) == 'c')
		local_write = ft_putchar_fd(va_arg(args, int32_t), fd);
	else if (*(format + 1) == 's')
		local_write = ft_putstr_fd_null(va_arg(args, char *), fd);
	else if (*(format + 1) == 'd' || *(format + 1) == 'i')
		local_write = ft_putnbr_fd(va_arg(args, int), fd);
	else if (*(format + 1) == 'u')
		b = DEC_BASE;
	else if (*(format + 1) == 'x')
		b = HEX_LOW;
	else if (*(format + 1) == 'X')
		b = HEX_UPP;
	else if (*(format + 1) == 'p')
		local_write = print_pointer(va_arg(args, void *), fd, error);
	else
		*error = true;
	if (*(format + 1) == 'u' || *(format + 1) == 'x' || *(format + 1) == 'X')
		local_write = ft_putuint_base_fd(va_arg(args, uint32_t), b, fd, error);
	return (local_write);
}

int32_t	pre_check(t_ffile fd, const char *format, va_list args)
{
	char	*str;
	int32_t	result;

	if (!ft_strchr(format, '%'))
	{
		result = ft_putstr_fd(format, fd);
		return (result);
	}
	if (!ft_strcmp(format, "%s\n"))
	{
		str = va_arg(args, char *);
		result = ft_putendl_fd_null(str, fd);
		return (result);
	}
	if (!ft_strcmp(format, "%s"))
	{
		str = va_arg(args, char *);
		result = ft_putstr_fd_null(str, fd);
		return (result);
	}
	return (0);
}
