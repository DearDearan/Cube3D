/* ************************************************************************** */
/*                                                                            */
/*                                                       ⠀⠀⠀⠀⠀⠀⣴⣾⣿⣿⣿⠷⢠⣤⡀      */
/*   execution.c                                         ⠀⢀⣀⣀⣛⡑⢶⣬⣭⢩⣶⣿⣷⣭⢻⣦⡀    */
/*                                                       ⣴⠛⢿⡟⠛⢿⣦⠹⣿⡆⣿⣿⣿⣿⣷⢩⡶⠃   */
/*   By: rboutelo <rboutelo@student.42.fr>               ⣿⣖⠾⢗⣶⣾⣿⡇⠿⠷⠸⠿⢟⣛⡵⣫     */
/*                                                       ⠙⢿⣿⣿⣿⣿⣿⣿⣮⣭⣭⣭⡭⣶⣾⣿     */
/*   Created: 2026/05/31 19:29:15 by rboutelo           ⠀⠀⣿⣿⣿⠛⠛⠛⣿⣿⣿⠁⠀⠀⠉⠁      */
/*   Updated: 2026/09/24 04:59:08 by rboutelo           ⠀⠀⠙⠛⠉⠀⠀⠀⠻⠿⠟           */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_get_exit_code_from_status(int32_t status)
{
	int32_t	signal;

	if (WIFSIGNALED(status))
	{
		signal = WTERMSIG(status);
		if (signal != SIGINT && signal != SIGPIPE)
		{
			if (status & 0x80)
				ft_dprintf(2, "\n(core dumped)");
		}
		ft_dprintf(2, "\n");
		return (signal + 128);
	}
	else if (WIFSTOPPED(status))
		return (WSTOPSIG(status) + 128);
	else if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFCONTINUED(status))
		return (0);
	return (-1);
}

// @doc ft_get_executable
// @kind func
// @desc Returns the first string of a command line prepanded with a /.
// @param str: const char *, Command line of which you need the executable.
// @returns char *, Executable prepended with /.
char	*ft_get_executable(const char *str)
{
	char	*result;

	result = ft_calloc(ft_fwlen(str) + 1, sizeof(char));
	ft_strlcat(result, str, ft_fwlen(str) + 1);
	return (result);
}

// @doc ft_find_exec
// @kind func
// @desc Returns the path to the executable name.
// @param name: const char *, name of the executable prepended with a /.
// @param path: char const **, PATH, most likely gotten through main.
// @returns char *, Path to the executable.
char	*ft_find_exec(const char *name, char const **path)
{
	char	*result;

	if (!name || !ft_strcmp(".", name) || !ft_strcmp("..", name))
		errno = EINVAL;
	if (!name || !ft_strcmp(".", name) || !ft_strcmp("..", name))
		return (NULL);
	if (name && name[0] != '/' && ft_strchr(name, '/'))
	{
		result = ft_extend(ft_extend(getcwd(NULL, 0), "/"), (char *)name);
		if (!access(result, F_OK))
			return (result);
		free(result);
	}
	while (path++ && *(path - 1) && *name != '/')
	{
		result = ft_extend(ft_strjoin(*(path - 1), "/"), (char *)name);
		errno = !!access(result, F_OK);
		if (!errno)
			return (result);
		free(result);
	}
	if (name[0] != '/')
		errno = ENOENT;
	return (ft_strdup(name));
}
