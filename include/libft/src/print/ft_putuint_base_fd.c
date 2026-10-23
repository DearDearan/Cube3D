/* ************************************************************************** */
/*                                                                            */
/*                                                       ⠀⠀⠀⠀⠀⠀⣴⣾⣿⣿⣿⠷⢠⣤⡀      */
/*   ft_putuint_base_fd.c                                ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀    */
/*                                                       ⣴⠛⢿⡟⠛⢿⣦⠹⣿⡆⣿⣿⣿⣿⣷⢩⡶⠃   */
/*   By: rboutelo <rboutelo@student.42.fr>       ⣿⣖⠾⢗⣶⣾⣿⡇⠿⠷⠸⠿⢟⣛⡵⣫     */
/*                                                       ⠙⢿⣿⣿⣿⣿⣿⣿⣮⣭⣭⣭⡭⣶⣾⣿     */
/*   Created: 2026/05/04 04:57:33 by rboutelo             ⣿⣿⣿⠛⠛⠛⣿⣿⣿⠁⠀⠀⠉⠁      */
/*   Updated: 2026/08/15 06:35:30 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟           */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @doc ft_putuint_base_fd
// @kind func
// @desc Prints the unsigned number n to the fd fd in the base base.
// @param n: uint64_t, Number to print.
// @param base: char *, The base to print the number in.
// @param fd: [[t_ffile]], fd to print to.
// @returns int32_t, number of chars written, negative on error.
int32_t	ft_putuint_base_fd(uint64_t n, char *base, t_ffile fd, bool *error)
{
	int32_t		result;
	uint64_t	base_length;

	result = 0;
	base_length = ft_strlen(base);
	if (n >= base_length)
		result += ft_putuint_base_fd(n / base_length, base, fd, error);
	result += ft_putchar_fd(base[n % base_length], fd);
	if (result < 0 && error)
		*error = true;
	return (result);
}
