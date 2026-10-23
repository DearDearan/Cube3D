/* ************************************************************************** */
/*                                                                            */
/*                                                       ⠀⠀⠀⠀⠀⠀⣴⣾⣿⣿⣿⠷⢠⣤⡀      */
/*   utils.c                                             ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀    */
/*                                                       ⣴⠛⢿⡟⠛⢿⣦⠹⣿⡆⣿⣿⣿⣿⣷⢩⡶⠃   */
/*   By: rboutelo <rboutelo@student.42.fr>               ⣿⣖⠾⢗⣶⣾⣿⡇⠿⠷⠸⠿⢟⣛⡵⣫     */
/*                                                       ⠙⢿⣿⣿⣿⣿⣿⣿⣮⣭⣭⣭⡭⣶⣾⣿     */
/*   Created: 2026/05/04 04:55:50 by rboutelo             ⣿⣿⣿⠛⠛⠛⣿⣿⣿⠁⠀⠀⠉⠁      */
/*   Updated: 2026/08/18 11:28:10 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟           */
/*                                                                            */
/* ************************************************************************** */

#include "int_file.h"

// @doc get_total_iov_len
// @kind func
// @desc Gets the totak len of the provided iovs.
// @param iov: const [[t_iovec]], The list of iovecs.
// @param cnt: uintmax_t, The number of iovs.
// @return uintmax_t, The calculated total len.
inline uintmax_t	get_total_iov_len(const t_iovec *iov, uintmax_t cnt)
{
	uintmax_t	total;

	total = 0;
	while (cnt-- > 0)
		total += iov[cnt].iov_len;
	return (total);
}
