/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:37:53 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/14 15:32:43 by m-boukel         ###   ########.fr       */
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
		content = (t_env *)i->content;
		content = get_env_by_name("OLDPWD");
		if (content)
			content->value = s;
		else
			ft_lstadd_back(&g_vars.env, ft_lstnew(new_env_node("OLDPWD", s)));
	}
	else if (n == 1)
	{
		content = (t_env *)i->content;
		content = get_env_by_name("PWD");
		if (content)
			content->value = s;
		else
			ft_lstadd_back(&g_vars.env, ft_lstnew(new_env_node("PWD", s)));
	}
}

void	ft_cd(char **s)
{
	int		i;
	char	*cur_path;
	char	*new_path;
	char	*USER;

	cur_path = NULL;
	new_path = NULL;
	i = 1;
	cur_path = getcwd(cur_path, sizeof(cur_path));
	add_pwd(cur_path, 1);
	if (chdir(s[i]) == 0)
	{
		new_path = getcwd(new_path, sizeof(new_path));
		add_pwd(cur_path, 0);
		add_pwd(new_path, 1);
	}
	else if (!s[1])
	{
		USER = expander("$HOME", 1);
		chdir(USER);
		ft_free((void **)&USER);
		new_path = getcwd(new_path, sizeof(new_path));
		add_pwd(cur_path, 0);
		add_pwd(new_path, 1);
	}
	else
		perror("ERROR ");
}
