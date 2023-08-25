/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 03:00:04 by m-boukel          #+#    #+#             */
/*   Updated: 2023/08/25 16:42:47 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/inc.h"

void	ft_pwd(void)
{
	char	*path;

	g_vars.exit_status = 0;
	path = getcwd(0, 0);
	ft_putendl_fd(path, 1);
	free(path);
}
