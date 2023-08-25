/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:37:53 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/25 17:55:51 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	add_pwd(char *s, int n)
{
	if (s == 0)
		s = "";
	if (n == 0)
		upsert_env_node(ft_strdup("OLDPWD"), ft_strdup(s), 0);
	else if (n == 1)
		upsert_env_node(ft_strdup("PWD"), ft_strdup(s), 0);
}

void	null_arg(char *cur_path, char *new_path)
{
	char	*home;

	home = expander("$HOME", false);
	if (chdir(home) == 0)
	{
		ft_free((void **)&home);
		new_path = getcwd(new_path, sizeof(new_path));
		add_pwd(cur_path, 0);
		add_pwd(new_path, 1);
	}
	else
	{
		ft_free((void **)&home);
		g_vars.exit_status = 1;
		perror("minishell: cd");
	}
}

void	ft_cd(char **s)
{
	char	*cur_path;
	char	*new_path;

	g_vars.exit_status = 0;
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
		null_arg(cur_path, new_path);
	else
	{
		g_vars.exit_status = 1;
		perror("minishell: cd");
	}
	free(new_path);
	free(cur_path);
}
