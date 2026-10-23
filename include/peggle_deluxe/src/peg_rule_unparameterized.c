/* ************************************************************************** */
/*                                                                            */
/*                                                       ⠀⠀⠀⠀⠀⠀⣴⣾⣿⣿⣿⠷⢠⣤⡀      */
/*   peg_rule_unparameterized.c                          ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀    */
/*                                                       ⣴⠛⢿⡟⠛⢿⣦⠹⣿⡆⣿⣿⣿⣿⣷⢩⡶⠃   */
/*   By: rboutelo <rboutelo@student.42angouleme.fr       ⣿⣖⠾⢗⣶⣾⣿⡇⠿⠷⠸⠿⢟⣛⡵⣫     */
/*                                                       ⠙⢿⣿⣿⣿⣿⣿⣿⣮⣭⣭⣭⡭⣶⣾⣿     */
/*   Created: 2026/09/29 06:30:01 by rboutelo           ⠀⠀⣿⣿⣿⠛⠛⠛⣿⣿⣿⠁⠀⠀⠉⠁      */
/*   Updated: 2026/09/29 06:30:02 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟           */
/*                                                                            */
/* ************************************************************************** */

#define PEGGLE_DELUXE_SOURCES
#include "peggle_deluxe.h"

PEG	*mk_dot(void)
{
	PEG	*res;

	res = mk_peg_rule(DOT);
	res->rule.dot_match.match = match_dot;
	return (res);
}

PEG	*mk_dstr_cap(void)
{
	PEG	*res;

	res = mk_peg_rule(CAPTURE);
	res->rule.cap_match.match = destroy_capture;
	return (res);
}

PEG	*mk_nd_anch(void)
{
	PEG	*res;

	res = mk_peg_rule(ANCHOR);
	res->rule.nch_match.pos = END;
	return (res);
}

PEG	*mk_strt_anch(void)
{
	PEG	*res;

	res = mk_peg_rule(ANCHOR);
	res->rule.nch_match.pos = START;
	return (res);
}
