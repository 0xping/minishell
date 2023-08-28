/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 03:00:04 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/25 17:52:39 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	ft_pwd(void)
{
	char	*path;
	t_env	*pwd_env;

	path = getcwd(0, 0);
	if (path == 0)
	{
		pwd_env = get_env_by_name("PWD");
		if (pwd_env)
			path = pwd_env->value;
		ft_putendl_fd(path, 1);
	}
	else
	{
		ft_putendl_fd(path, 1);
		free(path);
	}
}
