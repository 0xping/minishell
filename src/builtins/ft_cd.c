/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:37:53 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/23 11:39:50 by m-boukel         ###   ########.fr       */
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

	home = expander("$HOME", false, false);
	if (chdir(home) == 0)
	{
		ft_free((void **)&home);
		new_path = getcwd(new_path, sizeof(new_path));
		add_pwd(cur_path, 0);
		add_pwd(new_path, 1);
	}
	else
	{
		g_vars.exit_status = 1;
		perror("minishell: cd:");
	}
}

void	ft_cd(char **s)
{
	char	*cur_path;
	char	*new_path;

	cur_path = NULL;
	new_path = NULL;
	cur_path = getcwd(cur_path, sizeof(cur_path));
	add_pwd(cur_path, 1);
	if (chdir(s[1]) == 0)
	{
		new_path = getcwd(new_path, sizeof(new_path));
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
}
