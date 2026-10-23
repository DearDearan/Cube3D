/* ************************************************************************** */
/*                                                                            */
/*                                                       ⠀⠀⠀⠀⠀⠀⣴⣾⣿⣿⣿⠷⢠⣤⡀      */
/*   peggle_deluxe.h                                     ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀    */
/*                                                       ⣴⠛⢿⡟⠛⢿⣦⠹⣿⡆⣿⣿⣿⣿⣷⢩⡶⠃   */
/*   By: rboutelo <rboutelo@student.42angouleme.fr       ⣿⣖⠾⢗⣶⣾⣿⡇⠿⠷⠸⠿⢟⣛⡵⣫     */
/*                                                       ⠙⢿⣿⣿⣿⣿⣿⣿⣮⣭⣭⣭⡭⣶⣾⣿     */
/*   Created: 2026/09/29 06:30:20 by rboutelo           ⠀⠀⣿⣿⣿⠛⠛⠛⣿⣿⣿⠁⠀⠀⠉⠁      */
/*   Updated: 2026/10/18 04:43:19 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟           */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEGGLE_DELUXE_H
# define PEGGLE_DELUXE_H
# include <stdbool.h>
# ifdef PEGGLE_DELUXE_SOURCES
#  include "peggle_deluxe_int.h"
# endif
# ifndef PEG
#  define PEG t_peg_rule
# endif
# ifndef MAX_MATCHES
#  define MAX_MATCHES 20
# endif

typedef struct s_peg_rule	t_peg_rule;

void			*free_peg(PEG *p);
bool			match(PEG *peg, char *str, char **matches);
PEG				*peg(char *pat);

#endif // CCPEG_H
