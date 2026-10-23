/* ************************************************************************** */
/*                                                                            */
/*                                                       ⠀⠀⠀⠀⠀⠀⣴⣾⣿⣿⣿⠷⢠⣤⡀      */
/*   ft_printf.c                                         ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀    */
/*                                                       ⣴⠛⢿⡟⠛⢿⣦⠹⣿⡆⣿⣿⣿⣿⣷⢩⡶⠃   */
/*   By: rboutelo <rboutelo@student.42.fr       ⣿⣖⠾⢗⣶⣾⣿⡇⠿⠷⠸⠿⢟⣛⡵⣫     */
/*                                                       ⠙⢿⣿⣿⣿⣿⣿⣿⣮⣭⣭⣭⡭⣶⣾⣿     */
/*   Created: 2026/05/04 04:57:49 by rboutelo             ⣿⣿⣿⠛⠛⠛⣿⣿⣿⠁⠀⠀⠉⠁      */
/*   Updated: 2026/08/15 06:35:51 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟           */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int32_t	ft_dprintf_int(t_ffile fd, const char *format, va_list args)
{
	int32_t	total_write;
	bool	error;

	error = false;
	total_write = pre_check(fd, format, args);
	if (total_write)
		return (total_write);
	while (format && *format)
	{
		if (*format == '%' && *(format + 1))
			total_write += inject(format, args, &error, fd);
		else
		{
			ft_putstrn_fd(format, fd, get_next(format, &error));
			total_write += get_next(format, &error);
		}
		format += get_next(format, &error);
	}
	if (error || !format)
		return (-1);
	return (total_write);
}

// @doc ft_dprintf
// @kind func
// @desc Same behaviour as dprintf but limited to c, s, p, d, i, u, x and X.
// @param fd: [[t_ffile]], the fd to write to.
// @param format: char *, the format string.
// @param ...: variadic, the args.
// @returns int32_t, number of printed chars.
__attribute__ ((format (printf, 2, 3)))
int32_t	ft_dprintf(t_ffile fd, const char *format, ...)
{
	va_list	args;
	int32_t	result;

	va_start(args, format);
	result = ft_dprintf_int(fd, format, args);
	va_end(args);
	return (result);
}

// @doc ft_printf
// @kind func
// @desc Same behaviour as printf but limited to c, s, p, d, i, u, x and X.
// @param format: char *, the format string.
// @param ...: variadic, the args.
// @returns int32_t, number of printed chars.
__attribute__ ((format (printf, 1, 2)))
int32_t	ft_printf(const char *format, ...)
{
	va_list	args;
	int32_t	result;

	va_start(args, format);
	result = ft_dprintf_int(STDOUT_FILENO, format, args);
	va_end(args);
	return (result);
}
