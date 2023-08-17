/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:37:53 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/17 14:22:14 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	add_pwd(char *s, int n)
{
	t_list	*i;
	t_env	*content;

	i = g_vars.env;
	if (n == 0)
	{
		content = get_env_by_name("OLDPWD");
		if (content)
			content->value = s;
		else
			ft_lstadd_back(&g_vars.env, ft_lstnew(new_env_node("OLDPWD", s)));
	}
	else if (n == 1)
	{
		content = get_env_by_name("PWD");
		if (content)
			content->value = s;
		else
			ft_lstadd_back(&g_vars.env, ft_lstnew(new_env_node("PWD", s)));
	}
}

void	ft_cd(char **s)
{
	char	*cur_path;
	char	*new_path;
	char	*HOME;

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
	{
		HOME = expander("$HOME", 1);
		if (chdir(HOME) == 0)
		{
			ft_free((void **)&HOME);
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
	else
	{
		g_vars.exit_status = 1;
		perror("minishell: cd");
	}
}
