/* ************************************************************************** */
/*                                                                            */
/*                                                       ⠀⠀⠀⠀⠀⠀⣴⣾⣿⣿⣿⠷⢠⣤⡀      */
/*   parse.c                                             ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀    */
/*                                                       ⣴⠛⢿⡟⠛⢿⣦⠹⣿⡆⣿⣿⣿⣿⣷⢩⡶⠃   */
/*   By: rboutelo <rboutelo@student.42angouleme.fr       ⣿⣖⠾⢗⣶⣾⣿⡇⠿⠷⠸⠿⢟⣛⡵⣫     */
/*                                                       ⠙⢿⣿⣿⣿⣿⣿⣿⣮⣭⣭⣭⡭⣶⣾⣿     */
/*   Created: 2026/09/29 06:32:53 by rboutelo           ⠀⠀⣿⣿⣿⠛⠛⠛⣿⣿⣿⠁⠀⠀⠉⠁      */
/*   Updated: 2026/09/29 06:37:16 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟           */
/*                                                                            */
/* ************************************************************************** */

#define PEGGLE_DELUXE_SOURCES
#include "peggle_deluxe.h"

PEG	*parse_trivial(char **s)
{
	if (**s == '\'' || **s == '"')
		return (mk_lit_match(parse_lit(s), false));
	if (**s == '[')
		return (mk_class_match(parse_class(s)));
	if (**s == '.')
	{
		++*s;
		return (mk_dot());
	}
	return (NULL);
}

PEG	*parse_insensitive(char **s)
{
	int32_t	n;
	bool	backward;

	if (**s == 'i')
	{
		if (*++*s == '"' || **s == '\'')
			return (mk_lit_match(parse_lit(s), true));
		if (**s == '$')
		{
			++*s;
			if (**s == '^')
				(*s)++;
			if (ft_isdigit(**s))
			{
				backward = (*(*s - 1) == '^');
				n = ft_atoi(*s);
				while (ft_isdigit(**s))
					++*s;
				if (backward)
					return (mk_backref(-n, true));
				return (mk_backref(n, true));
			}
		}
	}
	return (parse_trivial(s));
}

PEG	*parse_money(char **s)
{
	int32_t	n[2];

	if (**s == '$')
	{
		++*s;
		if (**s == '^')
			++*s;
		if (ft_isdigit(**s))
		{
			n[1] = (*(*s - 1) == '^');
			n[0] = ft_atoi(*s);
			while (ft_isdigit(**s))
				++*s;
			if (n[1])
				return (mk_backref(-n[0], false));
			return (mk_backref(n[0], false));
		}
		return (mk_nd_anch());
	}
	if (**s == '^')
	{
		++*s;
		return (mk_strt_anch());
	}
	return (parse_insensitive(s));
}

PEG	*parse_cap(char **s)
{
	PEG	*res;

	if (**s == '{')
	{
		(*s)++;
		skip_spc(s);
		if (**s == '}')
		{
			++*s;
			return (mk_dstr_cap());
		}
		res = parse_choiche(s);
		skip_spc(s);
		if (**s != '}')
		{
			free_peg(res);
			errno = EINVAL;
			return (NULL);
		}
		++*s;
		return (mk_cap(res));
	}
	return (parse_money(s));
}

PEG	*parse_par(char **s)
{
	PEG	*res;

	if (!**s)
		errno = EINVAL;
	if (!**s)
		return (NULL);
	if (**s == '(')
	{
		(*s)++;
		skip_spc(s);
		res = parse_choiche(s);
		skip_spc(s);
		if (**s != ')')
		{
			free_peg(res);
			errno = EINVAL;
			return (NULL);
		}
		++*s;
		return (mk_grp(res));
	}
	return (parse_cap(s));
}
