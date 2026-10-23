/* ************************************************************************** */
/*                                                                            */
/*                                                       ⠀⠀⠀⠀⠀⠀⣴⣾⣿⣿⣿⠷⢠⣤⡀      */
/*   long_conversion.c                                   ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀    */
/*                                                       ⣴⠛⢿⡟⠛⢿⣦⠹⣿⡆⣿⣿⣿⣿⣷⢩⡶⠃   */
/*   By: rboutelo <rboutelo@student.42.fr>               ⣿⣖⠾⢗⣶⣾⣿⡇⠿⠷⠸⠿⢟⣛⡵⣫     */
/*                                                       ⠙⢿⣿⣿⣿⣿⣿⣿⣮⣭⣭⣭⡭⣶⣾⣿     */
/*   Created: 2026/08/09 02:00:37 by rboutelo           ⠀⠀⣿⣿⣿⠛⠛⠛⣿⣿⣿⠁⠀⠀⠉⠁      */
/*   Updated: 2026/08/18 11:28:12 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟           */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t	ft_atol(const char *str)
{
	__int128_t	result;
	int8_t		negative;
	int32_t		i;

	negative = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i++] == '-')
		negative = 1;
	else if (str[--i] == '+')
		i++;
	result = 0;
	while (ft_isdigit(str[i]) && result < INT64_MAX)
		result = (result * 10) + (str[i++] - '0');
	while (ft_isspace(str[i]))
		i++;
	if ((__uint128_t)result > (__uint128_t)INT64_MAX + negative
		|| str[i])
		errno = EINVAL;
	else
		errno = 0;
	if (negative)
		return (-result);
	return (result);
}
