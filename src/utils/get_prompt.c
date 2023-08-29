/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:00:14 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/29 15:42:33 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

static char	*g_path(void)
{
	char	*path;

	path = getcwd(0, 0);
	if (path)
		return (path);
	if (get_env_by_name("PWD"))
		return (ft_strdup(get_env_by_name("PWD")->value));
	return (0);
}

char	*get_cwd(void)
{
	char	*path;
	char	*result;
	t_env	*home_env;

	path = g_path();
	home_env = get_env_by_name("HOME");
	result = 0;
	if (char_count(path, '/') == 1)
		return (path);
	else
	{
		if (home_env && !ft_strcmp(home_env->value, path))
		{
			free(path);
			return (ft_strdup("~"));
		}
	}
	if (ft_strrchr(path, '/'))
		result = ft_strdup(ft_strrchr(path, '/') + 1);
	free(path);
	return (result);
}

char	*get_prompt(void)
{
	char	*prompt;
	char	*cwd;

	cwd = get_cwd();
	if (g_vars.exit_status == 0)
	{
		prompt = join_strings((char *[]){COLOR_GREEN "➜ " RESET_ALL
				TEXT_BOLD COLOR_BLUE, cwd, RESET_ALL}, 3, " ");
	}
	else
		prompt = join_strings((char *[]){COLOR_RED "➜ " RESET_ALL
				TEXT_BOLD COLOR_BLUE, cwd, RESET_ALL}, 3, " ");
	free(cwd);
	return (prompt);
}
