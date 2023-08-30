/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:37:53 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/30 20:00:22 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	add_pwd(char *s, int n)
{
	if (s == 0)
		return ;
	if (n == 0)
		upsert_env_node(ft_strdup("OLDPWD"), ft_strdup(s), 0);
	else if (n == 1)
		upsert_env_node(ft_strdup("PWD"), ft_strdup(s), 0);
}

void	null_arg(char *cur_path)
{
	char	*home;
	char	*new_path;

	new_path = 0;
	home = expander("$HOME", false);
	if (chdir(home) == 0)
	{
		new_path = getcwd(0, 0);
		add_pwd(cur_path, 0);
		add_pwd(new_path, 1);
	}
	else
	{
		g_vars.exit_status = 1;
		perror("minishell: cd");
	}
	ft_free((void **)&new_path);
	ft_free((void **)&home);
}

int	to_many_args(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (i > 2)
	{
		ft_putendl_fd("minishell: cd: too many arguments", 2);
		g_vars.exit_status = 1;
		return (1);
	}
	return (0);
}

void	ft_cd(char **s)
{
	char	*cur_path;
	char	*new_path;

	g_vars.exit_status = 0;
	if (to_many_args(s))
		return ;
	new_path = NULL;
	cur_path = getcwd(0, 0);
	add_pwd(cur_path, 1);
	if (chdir(s[1]) == 0)
	{
		new_path = getcwd(0, 0);
		add_pwd(cur_path, 0);
		add_pwd(new_path, 1);
	}
	else if (!s[1])
		null_arg(cur_path);
	else
	{
		g_vars.exit_status = 1;
		perror("minishell: cd");
	}
	free(new_path);
	free(cur_path);
}
