/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 08:47:18 by xshel             #+#    #+#             */
/*   Updated: 2023/08/01 08:48:00 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**get_lines(t_env *p, int fd)
{
	char	**paths;
	char	*a;
	int		i;

	i = 0;
	a = NULL;
	while (p)
	{
		if (ft_strcmp(p->name, "PATH") == 0)
			a = p->value;
		p = p->next;
	}
	if (!a)
	{
		write(fd, "command not found\n", 19);
		exit(127);
	}
	paths = ft_split(a + 5, ':');
	return (paths);
}

void	check_cmd(char *cmd, char **op, int fd)
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
			write(fd, "Error : No such file or directory\n", 35);
			exit(1);
		}
		i++;
	}
}

char	*get_path(char *cmd, int fd)
{
	int		j;
	char	**op;
	char	*path;
	int		i;
	t_env	*p;

	j = 0;
	p = my_env;
	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	op = get_lines(p, fd);
	check_cmd(cmd, op, fd);
	while (op[j])
	{
		op[j] = ft_strjoin(op[j], "/");
		path = ft_strjoin(op[j], cmd);
		free(op[j]);
		if (access(path, X_OK) != -1)
			return (path);
		free(path);
		j++;
	}
	write(fd, "command not found\n", 19);
	return (exit(127), NULL);
}