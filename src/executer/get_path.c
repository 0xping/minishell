/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 08:47:18 by xshel             #+#    #+#             */
/*   Updated: 2023/08/26 10:08:14 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"
#include <dirent.h>

char	**get_lines(void)
{
	char	**paths;
	t_env	*path_env;

	path_env = get_env_by_name("PATH");
	if (!path_env)
	{
		ft_putstr_fd("minishell : command not found\n", 2);
		g_vars.exit_status = 127;
		exit(127);
	}
	paths = ft_split(path_env->value, ':');
	return (paths);
}

void	check_cmd(char *cmd, char **op)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (int)ft_strlen(cmd))
	{
		if (cmd[i] == '/' || cmd[0] == '.')
		{
			while (op[j])
				free(op[j++]);
			g_vars.exit_status = 127;
			exit(127);
		}
		i++;
	}
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

void	check_dir(char *s)
{
	DIR	*dir;

	dir = opendir(s);
	if (dir)
	{
		g_vars.exit_status = 126;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": Is a directory\n", 2);
		g_vars.exit_status = 126;
		exit(g_vars.exit_status);
	}
}

char	*get_path(char **cmd)
{
	int		j;
	char	**op;
	char	*path;
	char	*tmp;

	j = 0;
	g_vars.exit_status = 0;
	check_dir(cmd[0]);
	if (access(cmd[0], X_OK) == 0)
		return (cmd[0]);
	op = get_lines();
	check_cmd(cmd[0], op);
	while (op[j])
	{
		tmp = ft_strjoin(op[j], "/");
		path = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (access(path, X_OK) != -1)
			return (free_paths(op), path);
		free(path);
		j++;
	}
	free_paths(op);
	ft_putstr_fd("minishell : command not found\n", 2);
	return (g_vars.exit_status = 127, exit(127), NULL);
}
