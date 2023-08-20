/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 08:47:18 by xshel             #+#    #+#             */
/*   Updated: 2023/08/19 22:11:14 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

char	**get_lines(void)
{
	char	**paths;
	t_env	*PATH_env;

	PATH_env = get_env_by_name("PATH");
	if (!PATH_env)
	{
		write(2, "command not found\n", 19);
		exit(127);
	}
	paths = ft_split(PATH_env->value, ':');
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
			write(2, "Error : No such file or directory\n", 35);
			exit(1);
		}
		i++;
	}
}

void free_paths(char **paths)
{
	int i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);

}

char	*get_path(char **cmd)
{
	int		j;
	char	**op;
	char	*path;
	char	*tmp;

	j = 0;
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
			return (free_paths(op),path);
		free(path);
		j++;
	}
	free_paths(op);
	ft_putstr_fd("command not found\n", 2);
	return (exit(127), NULL);
}

bool	is_builtins(char **cmd)
{
	if (!ft_strcmp(cmd[0], "cd"))
		return (1);
	if (!ft_strcmp(cmd[0], "echo"))
		return (1);
	if (!ft_strcmp(cmd[0], "env"))
		return (1);
	if (!ft_strcmp(cmd[0], "export"))
		return (1);
	if (!ft_strcmp(cmd[0], "unset"))
		return (1);
	if (!ft_strcmp(cmd[0], "exit"))
		return (1);
	if (!ft_strcmp(cmd[0], "pwd"))
		return (1);
	return (0);
}
