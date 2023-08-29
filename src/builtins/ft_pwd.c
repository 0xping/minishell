/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 03:00:04 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/29 15:42:00 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	ft_pwd(void)
{
	char	*path;

	path = getcwd(0, 0);
	if (path == 0 && get_env_by_name("PWD") && get_env_by_name("PWD")->value
		&& ft_strlen(get_env_by_name("PWD")->value))
		ft_putendl_fd(get_env_by_name("PWD")->value, 1);
	else
	{
		ft_putendl_fd(path, 1);
		free(path);
	}
}
