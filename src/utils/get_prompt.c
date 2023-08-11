/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:00:14 by aait-lfd          #+#    #+#             */
/*   Updated: 2023/08/11 01:10:54 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

char	*get_cwd(void)
{
	char	*path;
	char	*result;
	char	*home_path;

	path = getcwd(0, 0);
	result = 0;
	if (char_count(path, '/') == 1)
		return (path);
	else
	{
		home_path = ft_strjoin("/Users/", get_env_by_name("USER")->value);
		if (!ft_strcmp(home_path, path))
		{
			free(path);
			free(home_path);
			return (ft_strdup("~"));
		}
	}
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
		prompt = join_strings((char *[]){COLOR_GREEN "➜ " RESET_ALL TEXT_BOLD COLOR_BLUE,
			cwd, RESET_ALL}, 3, " ");
	}
	else
		prompt = join_strings((char *[]){COLOR_RED "➜ " RESET_ALL TEXT_BOLD COLOR_BLUE,
			cwd, RESET_ALL}, 3, " ");
	free(cwd);
	return (prompt);
}
