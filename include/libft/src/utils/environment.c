/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                       ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀    */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutelo <rboutelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 22:45:52 by rboutelo          #+#    #+#             */
/*   Updated: 2026/08/18 06:22:27 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟           */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @doc get_env
// @kind func
// @desc Returns value of the variable name in env.
// @param name: const char *, name of the variable to get the value of.
// @param env: char *const *, Environment, likely gotten from main.
// @returns char *, The retrieved value.
char	*ft_get_env(const char *name, char *const *env)
{
	while (*env)
	{
		if (!ft_strncmp(name, *env, ft_strlen(name)))
		{
			if (*((*env) + ft_strlen(name)) == '=')
				return ((*env) + ft_strlen(name) + 1);
		}
		env++;
	}
	return (*env);
}

// @doc set_var
// @kind func
// @desc Sets the var pointed to by var to val.
// @param var: char **, Pointer to var, will likely be re-allocated.
// @param val: char *, Value to set var to.
void	ft_set_var(char **var, char *val)
{
	size_t	var_start;
	size_t	value_len;

	var_start = 0;
	while ((*var)[var_start] && (*var)[var_start] != '=')
		var_start++;
	value_len = ft_strlen(val);
	*var = ft_recalloc(*var, ft_strlen(*var),
			var_start + 1 + value_len + 1, sizeof(char));
	(*var)[var_start] = '=';
	ft_strlcpy(*var + var_start + 1, val, value_len + 1);
}

// @doc set_env
// @kind func
// @desc Set the variable name to value value in env.
// @param name: const char *, The name of the variable to set in the env.
// @param env: char ***, The environment to the the variable in (in heap).
// @param value: char *, The value to set name to.
void	ft_set_env(const char *name, char ***env, char *value)
{
	char		**var;
	char		**oenv;
	uintmax_t	len;

	var = NULL;
	len = 0;
	oenv = *env;
	while (*oenv)
	{
		if ((!ft_strncmp(name, *oenv, ft_strlen(name))
				&& (*oenv)[ft_strlen(name)] == '=') || !ft_strcmp(name, *oenv))
			var = oenv;
		oenv++;
		len++;
	}
	if (!var)
	{
		*env = ft_recalloc(*env, ft_nt_tablen((void *)*env) * sizeof(char *),
				(len + 2), sizeof(char *));
		(*env)[len] = ft_calloc(ft_strlen(name) + 2, sizeof(char));
		ft_strlcpy((*env)[len], name, ft_strlen(name) + 1);
		(*env)[len + 1] = NULL;
		var = &(*env)[len];
	}
	ft_set_var(var, value);
}

void	ft_set_env_no_val(const char *name, char ***env)
{
	char		**oenv;
	uintmax_t	len;

	len = 0;
	oenv = *env;
	while (*oenv)
	{
		if ((!ft_strncmp(name, *oenv, ft_strlen(name))
				&& (*oenv)[ft_strlen(name)] == '=') || !ft_strcmp(name, *oenv))
			return ;
		oenv++;
		len++;
	}
	*env = ft_recalloc(*env, ft_nt_tablen((void *)*env) * sizeof(char *),
			(len + 2), sizeof(char *));
	(*env)[len] = ft_calloc(ft_strlen(name) + 2, sizeof(char));
	ft_strlcpy((*env)[len], name, ft_strlen(name) + 1);
	(*env)[len + 1] = NULL;
}

// @doc set_exit_code
// @kind func
// @desc Sets ? in env to the stringified code.
// @param code: int32_t, Code to set ? to.
// @param env: char ***, Pointer to the env to set ? in.
void	ft_set_exit_code(int32_t code, char ***env)
{
	char	*its;

	its = ft_itoa(code % 256);
	ft_set_env("?", env, its);
	free(its);
}
